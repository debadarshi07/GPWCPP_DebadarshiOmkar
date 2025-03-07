#include <iostream>
using namespace std;

int x[100];
int main() {
    cout << x[99] << endl;
}

/*
    O/P
    0
    Default value at all indices of an array is 0
*/