#include <iostream>
using namespace std;
void myfun(int i, int &k) {
    i = 1;
    k = 2;
}
int main() {
    int x = 0;
    myfun(x, x);
    cout << x << endl;
    return 0;
}

/*
    O/P
    2
    x has been updated as there is an argument in the myfun function which takes the reference of variable x.
*/