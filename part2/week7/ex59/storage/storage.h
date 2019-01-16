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
    std::queue<std::string*> d_data;
    bool d_finished;

    public:
        Storage();
        bool empty() const;
        size_t size() const;
        std::string front();
        void push(std::string &str);
        void pop();
        bool finished();
        void setFinished();
};

inline bool Storage::empty() const
{
    return d_data.empty();
}

inline size_t Storage::size() const
{
    return d_data.size();
}
#endif
