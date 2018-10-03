#include "main.ih"


void read_people(Person people[], size_t count)
{
    for (size_t idx = 0; idx < count; ++idx)
    {
        cout << "? ";
        people[idx].extract(cin);
    }
}