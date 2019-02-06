#ifndef WORKFORCE_H
#define WORKFORCE_H

#include <iostream>
#include <fstream>
#include <mutex>
#include <queue>
#include <string>


#include "semaphore.h"

class WorkForce
{
    Semaphore d_availableWorkers;
    Semaphore d_workers;
    Semaphore d_outHandler;
    Semaphore d_results;

    std::mutex d_inputMutex;
    std::queue<std::string> d_inputQueue;
    std::queue<std::string> d_resultQueue;

    public:
        WorkForce();
        void run(char const *infile, char const *outfile);
        void run(std::istream &instream, std::ostream &outstream);

    private:
        void process(std::istream &instream, std::ostream &outstream);
        void output(std::ostream &outstream);
        bool lineInQueue(std::string &line);
        void task();
};

#endif