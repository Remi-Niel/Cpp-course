#include "worker.ih"

Worker::Worker(BigInt const &max)
:   
    d_done(false),
    d_max(max),
    d_next(1),
    d_global_result(0)
{
    d_chunks.resize((max / BigInt(CHUNKSIZE)).convert_to<size_t>(), Result{0});
}