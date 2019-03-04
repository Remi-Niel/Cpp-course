#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "Expression.h"

using namespace std;

typedef vector<int> IVect;
typedef vector<double> DVect;

int main()
{
    IVect iv1(10,4);
    IVect iv2(10,3);
    IVect iv3(10,2);
    IVect iv4(10,1);

    IVect iResult { iv1 * (iv2 + iv3) / iv4};
    
    DVect dv1(10,4);
    DVect dv2(10,3);
    DVect dv3(10,2);
    DVect dv4(10,1);

    DVect dResult { dv1 * (dv2 + dv3) / dv4};


    cout << iResult[0] << '\n';
    cout << dResult[0] << '\n';

}