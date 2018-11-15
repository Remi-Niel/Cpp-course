#include "lock.ih"

void Lock::get_file(string const &path)
{

    if (access(path.c_str(), F_OK) == -1)
        d_file = open(path.c_str(), O_CREAT | O_TRUNC | O_RDWR | 0600);
    else
        d_file = open(path.c_str(), 0600);

}