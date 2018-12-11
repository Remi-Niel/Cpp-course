#include "derived.h"

void Derived::v_hello(std::ostream &out)
{
    out << d_line;
}