#include <iostream>
using namespace std;

int x[100];
int main() {
    cout << x[99] << endl;
}

/*
    O/P
    0

    Default value at every indices of an uninitialized global array is 0.
*/