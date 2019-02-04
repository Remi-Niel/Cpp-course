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

        cout << "Result for " << result.d_value << ":\n";
        cout << "    seq length: " << result.d_length << "\n";
        cout << "       highest: " << result.d_highest << "\n";
        cout << "    pow4 count: " << result.d_pow4_count << "\n";
    }

}