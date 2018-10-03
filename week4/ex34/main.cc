#include "main.ih"

int main()
{
    size_t person_count = 2;
    Person people[person_count] = { };

    read_people(people, person_count);
    output_people(people, person_count);
}
