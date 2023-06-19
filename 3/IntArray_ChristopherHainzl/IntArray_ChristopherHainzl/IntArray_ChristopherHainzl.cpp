// IntArray_ChristopherHainzl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "intarray.h"
using namespace std;
int main() {
    IntArray a(10, 5);

    cout << "a.size() = " << a.size() << endl;
    cout << a << endl;

    IntArray b;
    b.resize(10);
    for (int i = 0; i < b.size(); i++)
        b[i] = i * i;

    cout << "b.size() = " << b.size() << endl;
    cout << b << endl;

    try {
        cout << a[12];
    }
    catch (Array_Error e) {
        cout << e.get_message() << endl;
    }

    IntArray c(b); //Copy ctor
    cout << "c.size() = " << c.size() << endl;
    cout << c << endl;

    if (c != b)
        cout << "IntArrays b,c not equal\n";
    else
        cout << "IntArrays b,c are equal\n";

}
