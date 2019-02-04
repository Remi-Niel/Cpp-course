#ifndef INCLUDED_WORKER_
#define INCLUDED_WORKER_

#include <queue>
#include <thread>

#include "../result.h"
#include "../semaphore/semaphore.h"

class Worker
{
    bool d_done;
    BigInt d_max;
    BigInt d_next;

    Semaphore d_worker;
    Semaphore d_worker_force;
    Semaphore d_output;
    Semaphore d_result;
    std::queue<BigInt> d_jobs;
    std::queue<Result> d_results;

    std::thread d_output_handler;
    std::vector<std::thread> d_workers;

    public:
        Worker(BigInt const &max);
        
        void run();

    private:
        static Result collatz(BigInt value);
        static bool is_pow4(BigInt value);

        void worker();
        void output_handler();
};

inline Worker::Worker(BigInt const &max)
:   
    d_done(false),
    d_max(max),
    d_next(1)
{ }

#endif
