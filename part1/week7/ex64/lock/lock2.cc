#include "lock.ih"

Lock::Lock(string path, string lockDir)
:   d_file(-1), d_lock(-1)
{
    string name = basename(path.data());
    string directory = dirname(path.data());
    
    if (lockDir.size() != 0)
        lockDir.append("/");


    string file = directory + "/" + lockDir + name + ".lck";
    cout << "directory: " << directory << "\n";
    cout << "file: " << name << "\n";
    cout << "filename: " << file << "\n";

    get_file(file);
    lock_file();
}