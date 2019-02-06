#include "producer.ih"

void Producer::run()
{
    size_t n_threads = thread::hardware_concurrency();

    // produce file list
    if (fs::is_directory(d_source))
        directory_producer();
    else
        list_producer();

    // start compilers
    for (size_t idx = 1; idx < n_threads; ++idx)
        d_compilers.push_back(thread(&Producer::worker, this));

    worker(); // this thread can work too.

    // all done, wait for threads and exit.
    for (auto &thread : d_compilers)
        thread.join();
}