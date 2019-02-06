#include "producer.ih"

Producer::Producer(string const &file)
:
    d_valid(true),
    d_source(file)
{ }