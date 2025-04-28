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

    when an enumerator is not given a value, by default it takes the value of the previous enumerator + 1, regardless of whether the previous one was assigned explicitly or implicitly.
*/