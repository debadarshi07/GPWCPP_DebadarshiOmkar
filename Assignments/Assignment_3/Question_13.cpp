#include <iostream>
using namespace std;

enum hello {
    a, b = 99, c, d = -1
};

main() {
    enum hello m;
    cout << a << " " << b << " " << c << " " << d << endl;
    return 0;
}

/*
    O/P
    0 99 100 -1
*/