#include "main.ih"


void read_people(Person people[], size_t count)
{
    // Show input prompt, then read a person from cin
    for (size_t idx = 0; idx < count; ++idx)
    {
        cout << "? ";
        people[idx].extract(cin);
    }
}