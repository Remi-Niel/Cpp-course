#ifndef INCLUDED_SEMAPHORE_
#define INCLUDED_SEMAPHORE_

#include <condition_variable>
#include <mutex>

class Semaphore
{
    size_t d_count;
    std::mutex d_mutex;
    std::condition_variable d_condition;

    public:
        Semaphore();

        void notify();
        void notify_all();
        
        void wait();
};
    
inline Semaphore::Semaphore()
:   d_count(0)
{ }

#endif
