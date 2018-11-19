#include "in.ih"

ostream &Strings::In::insertInto(ostream &out)
{
    for (size_t idx = 0; idx != d_str->size(); ++idx)
    {
        out << d_str->at(idx);
        if (idx >= d_begin && idx < d_end)
        {
            if (d_funPtr == nullptr) //If delim was provided use default function
                insertDelim(out, *d_str, idx);
            else                     //If not use provided function
                (*d_funPtr)(out, *d_str, idx);
        }
    }
    return out;
}
