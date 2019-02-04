#include "taskthreads.ih"

void TaskThreads::run()
{
    auto start = chrono::system_clock::now();

    // sequential
    if (args > 2)
    {
        cout << "\nrunning sequentially...\n\n";
        for (size_t iter = 0; iter != 4; ++iter)
        {
            tasks[iter]();
        }
    }
    
    // parallel
    else
    {
        cout << "\nrunning in parallel...\n\n";
        for (size_t iter = 0; iter != 4; ++iter)
        {
            threads[iter] = std::thread(std::ref(tasks[iter]));
        }
        for (size_t iter = 0; iter != 4; ++iter)
        {
            threads[iter].join();
        }
    }

    // get time after execution from clock, then store it in microseconds
    auto endtime = chrono::system_clock::now();
    runtime = chrono::duration_cast<chrono::microseconds>(endtime - start).count();

    // print results
    for (size_t iter = 0; iter != 4; ++iter)
    {
        cout << setw(25) << tasks[iter].taskname() << " : " 
             << tasks[iter].count() << '\n';
    }
}