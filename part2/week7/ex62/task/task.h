#ifndef TASK_H
#define TASK_H

#include <cctype>
#include <string>
 
typedef int (*task_function)(int);

class Task
{
    task_function d_is_function;

    char const *d_taskname;
    std::size_t d_count;

    public:
        Task(task_function is_function, char const *label);
        void operator()(char const *file);
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