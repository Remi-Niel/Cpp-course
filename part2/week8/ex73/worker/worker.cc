#include "worker.ih"

void Worker::worker()
{
    d_worker_force.notify();

    while(!d_done)
    {
        d_worker.wait();

        if(d_jobs.empty())
            return;
        
        BigInt job = d_jobs.front();
        d_jobs.pop();

        d_worker_force.notify();
        Result result = collatz(job);
        d_output.wait();
        d_results.push(result);
        d_result.notify();
    }
}   