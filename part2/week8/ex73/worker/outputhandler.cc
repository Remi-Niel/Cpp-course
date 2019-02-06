#include "worker.ih"

void Worker::output_handler()
{
    d_output.notify_all();

    while(true)
    {
        d_result.wait();

        if (d_results.empty())
            return;

        Result result = d_results.front();
        d_results.pop();
        d_output.notify_all();

        store_result(result);
    }

}