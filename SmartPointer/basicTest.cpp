#include <iostream>
#include "SmartPointer.h"
using namespace std;

int main(int argc, char const *argv[]) {

    SmartPointer<int> x(new int);
    SmartPointer<float> y(new float);
    SmartPointer<string> z(new string);

    *x = 5;
    *y = 3.14;
    *z = "hello!";

    cout << "x = " << *x << endl;
    cout << "y = " << *y << endl;
    cout << "z = " << *z << endl;

    SmartPointer<int> a;
    a = x;
    cout << "a = " << *a << endl;

    return 0;
}
