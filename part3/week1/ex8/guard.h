#ifndef GUARD_H
#define GUARD_H

#include <mutex>

template<typename func>
inline void guard(std::mutex &mut, func &function) 
{
    std::lock_guard<std::mutex> lg(mut);
    function();
}

#endif