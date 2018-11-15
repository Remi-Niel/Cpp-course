#include "converter.ih"

void Converter::setBits(uint8_t &bits, size_t idx, nucleobases base)
{
    bits |= base << (idx * 2);
}
