#include "converter.ih"

nucleobases Converter::enumVal(char base)
{
    switch (base)
    {
        case 'A':
            return A;
        case 'T':
            return T;
        case 'G':
            return G;
        case 'C':
            return C;
        default:
            exit(1);
    }
}
