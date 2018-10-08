#include "data.ih"

Data::~Data()
{
    delete d_impl;
}