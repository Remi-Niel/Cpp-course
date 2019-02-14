#include "matrix/matrix.h"

using namespace std;

int main()
{
    Matrix<int> intmat{4, 4};
    cin >> intmat;

    double darr[4][4] = 
    {
        1.2, 3.4, 5.6, 7.8,
        9.1, 11.12, 13.14, 15.16,
        17.18, 19.2, 21.22, 23.24,
        25.26, 27.28, 29.3, 31.32
    };
    Matrix<double> doubmat{darr};
    cout << doubmat << "\n";

    cout << intmat + doubmat << "\n";
    cout << doubmat + intmat << "\n";

    cout << intmat << "\n";
    intmat += intmat;
    cout << intmat << "\n";
}