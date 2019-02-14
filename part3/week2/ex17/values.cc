#include "values.h"

using namespace std;

IntValue::IntValue(int value)
:
    d_value(value)
{ }

int IntValue::value() const
{
    return d_value;
}

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