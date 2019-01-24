#include "taskthreads.h"
#include <iostream>

TaskThreads::TaskThreads(int argc, char* argv[])
:
    args(argc)
{
    d_filename = argv[1];
}

void TaskThreads::run()
{
    // sequential
    if (args > 2)
    {
        for (size_t iter = 0; iter != 4; ++iter)
        {
            tasks[iter]();
        }
    }
    
    // parallel
    else
    {
        for (size_t iter = 0; iter != 4; ++iter)
        {
            threads[iter] = std::thread(std::ref(tasks[iter]));
        }
        for (size_t iter = 0; iter != 4; ++iter)
        {
            threads[iter].join();
        }
    }

    // print results
    for (size_t iter = 0; iter != 4; ++iter)
    {
        std::cout << tasks[iter].taskname() << " : " << tasks[iter].count() << '\n';
    }
}