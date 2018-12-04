#include <utility>
#include "base.h"
#include "derived.h"

int main()
{
    Derived one{};
    one.printdata();

    Derived two(one);
    two.printdata();

    Derived three(std::move(one));
    three.printdata();
}
