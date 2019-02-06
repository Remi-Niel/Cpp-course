#pragma once

#include <queue>
#include <vector>
#include <filesystem>

#include "../compilation/compilation.h"
#include "../semaphore/semaphore.h"

class Producer
{
    bool d_valid;
    std::mutex d_queue_lock;

    std::queue<std::string> d_sourcefiles;
    std::vector<std::thread> d_compilers;

    std::filesystem::path d_source;

    public:
        Producer(std::string const &path);

        void run();

    private:
        void list_producer();
        void directory_producer();
        void worker();

        std::string next();

        //validity setter
        bool set_invalid();
};