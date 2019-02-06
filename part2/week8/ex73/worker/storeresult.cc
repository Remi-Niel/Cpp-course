#include "worker.ih"

void Worker::store_result(Result const &result)
{
    d_global_result.d_highest = max(result.d_highest, d_global_result.d_highest);
    d_global_result.d_length = max(result.d_length, d_global_result.d_length);
    d_global_result.d_pow4_count += result.d_pow4_count;
    
    size_t index = (result.d_value / BigInt(CHUNKSIZE)).convert_to<size_t>();
    d_chunks[index].d_highest = max(result.d_highest, d_chunks[index].d_highest);
    d_chunks[index].d_length = max(result.d_length, d_chunks[index].d_length);
    d_chunks[index].d_pow4_count += result.d_pow4_count;
    ++d_chunks[index].d_value;

    if (d_chunks[index].d_value == CHUNKSIZE)
        print_chunk(index);
}