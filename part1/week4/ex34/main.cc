#include "main.ih"

int main()
{
    // allocate space for persons
    size_t person_count = 2;
    Person people[person_count];

    // read and then output people.
    read_people(people, person_count);
    output_people(people, person_count);
}
