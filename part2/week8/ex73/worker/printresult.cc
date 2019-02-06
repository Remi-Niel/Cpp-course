#include "worker.ih"

void Worker::print_chunk(size_t index)
{
    cout << setw(6) << index + 1 << " .. ";
    cout << index * CHUNKSIZE << ":\n";

    cout << "  Current chunk:\n";
    cout << "    Longest: " << d_chunks[index].d_length << "\n";
    cout << "    Highest: " << d_chunks[index].d_highest << "\n";
    cout << "   num pow4: " << d_chunks[index].d_pow4_count << "\n";

    cout << "         Global:\n";
    cout << "    Longest: " << d_global_result.d_length << "\n";
    cout << "    Highest: " << d_global_result.d_highest << "\n";
    cout << "   num pow4: " << d_global_result.d_pow4_count << "\n";
}