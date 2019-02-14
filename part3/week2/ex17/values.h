#include "base.h"

class IntValue : public Base<IntValue>
{
    int d_value;

    public:
        IntValue(int value);

        int value() const;
        virtual void insert_into(std::ostream &out) const;
};

class DoubleValue : public Base<DoubleValue>
{
    double d_value;

    public:
        DoubleValue(double value);
        void insert_into(std::ostream &out) const;
};