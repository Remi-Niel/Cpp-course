#include "main.ih"

IntValue::IntValue(int value)
:
    d_value(value)
{ }

void IntValue::insert_into(ostream &out) const
{
    out << d_value;
}

DoubleValue::DoubleValue(double value)
:
    d_value(value)
{ }

void DoubleValue::insert_into(ostream &out) const
{
    out << d_value;
}

int main()
{

    IntValue intval{42};
    DoubleValue doubleval{13.37};

    cout << intval << " " << doubleval << "\n";

}