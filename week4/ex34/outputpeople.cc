#include "main.ih"

void output_people(Person people[], size_t count)
{
    // iterate over all people objects, and output their info
    for (size_t idx = 0; idx < count; ++idx)
        people[idx].insert(cout);
}