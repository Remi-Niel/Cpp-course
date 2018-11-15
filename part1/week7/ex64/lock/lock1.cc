#include "lock.ih"

Lock::Lock(string const &path)
: Lock(path, "")
{
}