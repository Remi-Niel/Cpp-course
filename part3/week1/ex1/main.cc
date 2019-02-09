#include "main.ih"

int main()
{

    max1(1337, 42);

    Function func;
    func.d_function = max<int>;

    cout << "main: calling max<int> at location " << func.d_address << "\n";
    cout << max<int>(19, 98) << "\n";
}