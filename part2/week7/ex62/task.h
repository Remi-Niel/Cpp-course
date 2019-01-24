#ifndef TASK_H
#define TASK_H

#include <cctype>

class Task
{
    int (*d_isFunction)(int);

    char const *d_taskname;
    std::size_t d_count;

    public:
        Task(int (*isFunction)(int), char const *label);
        void operator()();
        std::size_t count();
        char const *taskname();
};

inline char const *Task::taskname()
{
    return d_taskname;
}

inline std::size_t Task::count()
{
    return d_count;
}

#endif