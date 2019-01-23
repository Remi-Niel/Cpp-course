#ifndef INCLUDED_STORAGE_
#define INCLUDED_STORAGE_

#include <queue>
#include <list>
#include <string>
#include <mutex>

class Storage
{
    std::mutex qMutex;
    std::mutex finishedMutex;
    std::queue<std::string> d_data;
    bool d_finished;

    public:
        Storage();
        bool empty();
        size_t size();
        std::string front();
        void push(std::string &str);
        bool pop(std::string &str);    
        bool finished();
        void setFinished();
};
#endif
