#include "worker.ih"

void Worker::run()
{
    size_t n_threads = thread::hardware_concurrency();

    if (n_threads < 3)
        cout << "Warning! more threads than core's.";

    cout << "Running on " << n_threads << " threads.\n";
    // fire up the output handler.
    d_output_handler = thread(&Worker::output_handler, this);

    // thread 0 = run, thread 1 = output_handler.
    for (size_t idx = 2; idx < n_threads; ++idx)
        d_workers.push_back(thread(&Worker::worker, this));

    // start pushing jobs, when workforce is available.
    while (++d_next <= d_max) //start @ 2.
    {
        d_worker_force.wait();
        d_jobs.push(d_next);
        d_worker.notify_all();
    }

    cout << "did everything, joining now.\n";
    // notify once for each thread that they can quit.
    for (size_t idx = 0; idx < n_threads; ++idx)
        d_worker.notify_all();

    // wait for all workers to be done.
    for (thread &worker : d_workers)    
        worker.join();

    // when all workers are done we know that all results are in the output
    // queue, so then we can safely signal the output_handler to quit.
    d_result.notify();
    d_output_handler.join();
}