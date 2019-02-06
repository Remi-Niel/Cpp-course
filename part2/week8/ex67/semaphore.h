#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>


class Semaphore
{
    mutable std::mutex d_mutex;
    std::condition_variable d_condition;
    size_t d_nAvailable;

    public:
        Semaphore(size_t nAvailable);
        void notify();
        void notify_all();
        size_t size() const;
        void wait();
};

#endif