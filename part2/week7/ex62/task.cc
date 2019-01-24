#include "task.h"
#include "taskthreads.h"
#include <fstream>

Task::Task(int (*isFunction)(int), char const *label)
:
    d_isFunction(isFunction),
    d_taskname(label),
    d_count(0)
{}

void Task::operator()()
{
    std::fstream fs{TaskThreads::d_filename, std::fstream::in};
    while (!fs.eof())
    {
        if (d_isFunction(fs.get()))
            d_count++;
    }
}