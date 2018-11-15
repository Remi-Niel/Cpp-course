#ifndef INCLUDED_LOCK_
#define INCLUDED_LOCK_

#include <iosfwd>
#include <sys/file.h>
#include <unistd.h>

class Lock
{
    int d_file;
    int d_lock;

    public:
        Lock(std::string const &path);
        Lock(std::string path, std::string lockDir);
        ~Lock();

        bool valid() const;

    private:
        void lock_file();
        void get_file(std::string const &file);
        
};

inline bool Lock::valid() const
{
    return d_lock >= 0;
}

inline void Lock::lock_file()
{
    d_lock = flock(d_file, LOCK_EX);
}

#endif
