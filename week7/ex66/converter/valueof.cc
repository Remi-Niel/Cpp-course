#include "converter.ih"

char Converter::valueOf(uint8_t bits, size_t idx)
{
    //Get correct bit pair and cast it to a nucleobase
    nucleobases base = static_cast<nucleobases>((bits >> (idx * 2)) % 4);

    switch (base)
    {
        case A:
            return 'A';
        case T:
            return 'T';
        case G:
            return 'G';
        case C:
            return 'C';
    }

    return 'E';
}
