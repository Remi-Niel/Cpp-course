#ifndef TASKTHREADS_H
#define TASKTHREADS_H

#include <thread>
#include <cctype>

#include "task.h"

class TaskThreads
{
    char *d_filename;
    size_t args;

    Task tasks[4] =
    {
        Task{&TaskThreads::isvowel, "vowels"},
        Task{isdigit, "digits"},
        Task{isxdigit, "hexadecimal digits"},
        Task{ispunct, "punctuation characters"}
    };
    std::thread threads[4];

    size_t runtime;

    friend void Task::operator()();

    public:
        TaskThreads(int argc, char* argv[]);
        void run();
        void showTime();

    private:
        static int isvowel(int ch);
};

#endif