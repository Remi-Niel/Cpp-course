#include "main.ih"

void output_people(Person people[], size_t count)
{
    for (size_t idx = 0; idx < count; ++idx)
        people[idx].insert(cout);
}