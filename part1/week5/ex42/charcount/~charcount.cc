#include "charcount.ih"

CharCount::~CharCount()
{
    delete[] d_charinfo.ptr;
}