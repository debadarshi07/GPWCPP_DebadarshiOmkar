#include <iostream>
using namespace std;
int x = 1;
void fun() {
    int x = 2; {
        int x = 3;
        cout << ::x << endl;
    }
}

int main() {
    fun();
    return 0;
}

/*
    O/P
    1
    Scope resolution operator has been used with x, which is used to access global variable(x).
*/