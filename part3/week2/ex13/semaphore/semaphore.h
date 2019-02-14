#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>


class Semaphore
{
    mutable std::mutex d_mutex;
    mutable std::mutex d_Wmutex;
    std::condition_variable d_condition;
    size_t d_nWaiting;
    size_t d_nAvailable;

    public:
        Semaphore();
        void notify();
        void notify_all();
        size_t size() const;
        size_t waiting() const;
        void wait(size_t nThreads);
    private:
        void incrementWaiting();
        void decrementWaiting();
};

inline void Semaphore::incrementWaiting()
{
    d_Wmutex.lock();
    ++d_nWaiting;
    d_Wmutex.unlock();
}

inline void Semaphore::decrementWaiting()
{
    d_Wmutex.lock();
    --d_nWaiting;
    d_Wmutex.unlock();
}

#endif