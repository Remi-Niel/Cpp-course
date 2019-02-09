#include "main.ih"

int max1(int lhs, int rhs)
{
    Function func;
    func.d_function = max<int>;

    cout << "max1: calling max<int> at location " << func.d_address << "\n";
    return max<int>(lhs, rhs);
}