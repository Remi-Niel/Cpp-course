#include "producer.ih"

void Producer::directory_producer()
{
    for (auto &path : fs::recursive_directory_iterator(d_source))
    {
        if (!path.is_regular_file())
            continue;

        if (path.path().extension().string() == ".cc")
            d_sourcefiles.push(path.path());
    }
}