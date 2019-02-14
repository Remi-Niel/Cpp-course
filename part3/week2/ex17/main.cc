#include "main.ih"


int main()
{

    IntValue intval{42};
    DoubleValue doubleval{13.37};
    LabelledInt label{"cashmoney", 1000000};

    cout << intval << " " << doubleval << "\n";
    cout << label << "\n";

}