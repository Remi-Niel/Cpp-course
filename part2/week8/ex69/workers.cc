#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <queue>
#include <mutex>
#include <functional>

using namespace std;

typedef packaged_task<double(double *, double *)> ptask;

enum { rowLength = 5 };

typedef struct TaskPackage
{
    ptask task;
    double *row;
    double *column;
} TaskPackage;

queue<TaskPackage> taskQueue;
mutex queueMutex;

// threads pop packaged tasks from queue and execute them until queue is empty
void multiplicationTask()
{
    while (true)
    {
        lock_guard<mutex> lock(queueMutex);
        if (not taskQueue.empty())
        {
            taskQueue.front().task(taskQueue.front().row, taskQueue.front().column);
            taskQueue.pop();
        }
        else break;
    }
}

int main()
{
    double lhs[4][5] = 
    {
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        9, 8, 7, 6, 5,
        4, 3, 2, 1, 0
    };
    double rhsT[6][5] =
    {
        0, 1, 2, 3, 4,
        5, 6, 7, 8, 9,
        10, 11, 12, 13, 14,
        15, 14, 13, 12, 11,
        10, 9, 8, 7, 6,
        5, 4, 3, 2, 1
    };

    future<double> fut[4][6];

    for (size_t outer = 0; outer != 4; ++outer)
    {
        for (size_t inner = 0; inner != 6; ++inner)
        {
            ptask task(
                [](double *row, double *col)
                {
                    return inner_product(row, row + rowLength, col, 0);
                });
            
            fut[outer][inner] = task.get_future();
            taskQueue.push(TaskPackage{move(task), lhs[outer], rhsT[inner]});         
        }
    }

    for (size_t idx = 0; idx != 8; ++idx)
    {
        thread(multiplicationTask).detach();
    }

    // print result
    for (size_t outer = 0; outer != 4; ++outer)
    {
        for (size_t inner = 0; inner != 6; ++inner)
        {
            cout << setw(4) << fut[outer][inner].get();
        }
        cout << '\n';
    }
}
