#include "workforce.h"
#include <thread>

WorkForce::WorkForce()
:
    d_availableWorkers(0),
    d_workers(0),
    d_outHandler(0),
    d_results(0)
{}

void WorkForce::run(char const *infile, char const *outfile)
{
    std::ifstream instream(infile);
    std::ofstream outstream(outfile);
    process(instream, outstream);
}

void WorkForce::run(std::istream &instream, std::ostream &outstream)
{
    process(instream, outstream);
}

void WorkForce::process(std::istream &instream, std::ostream &outstream)
{
    std::thread out(&WorkForce::output, this, std::ref(outstream));
    std::thread worker1(&WorkForce::task, this);
    std::thread worker2(&WorkForce::task, this);

    std::string line;
    while (getline(instream, line))
    {
        std::cout << line << '\n';
        d_availableWorkers.wait();      // wait for available worker

        // new scope for lock_guard
        {
            std::lock_guard<std::mutex> lg(d_inputMutex);
            d_inputQueue.push(line);
        }

        d_workers.notify();
    }

    std::cout << "failed to get new line\n";

    // once done, end threads
    d_workers.notify_all();
    worker1.join();
    d_workers.notify_all();
    worker2.join();
    d_results.notify();
    out.join();
}

void WorkForce::output(std::ostream &outstream)
{
    d_outHandler.notify();              // make out-handler 'available' 
    
    while (true)
    {
        std::string line;
        d_results.wait();               // wait for available results

        if (d_resultQueue.empty())
            return;                     // all lines have been output

        line = d_resultQueue.front();
        d_resultQueue.pop();
        d_outHandler.notify_all();      // notify all waiting workers

        outstream << line << '\n';
    }
}

bool WorkForce::lineInQueue(std::string &line)
{
    std::lock_guard<std::mutex> lg(d_inputMutex);
    
    if (d_inputQueue.empty())
        return false;

    line = d_inputQueue.front();
    line += ": processed";
    d_inputQueue.pop();
    return true;
}

void WorkForce::task()
{
    d_availableWorkers.notify();

    while (true)
    {
        d_workers.wait();
        std::string line;

        if (not lineInQueue(line))
        {
            d_availableWorkers.notify();
            break;
        }

        d_availableWorkers.notify();
        d_outHandler.wait();
        d_resultQueue.push(line);
        d_results.notify();
    }
}
