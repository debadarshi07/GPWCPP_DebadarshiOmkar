#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int& rnum = num;
    int& r1num = rnum;
    rnum = 100;
    cout << rnum << " " << num << " " << r1num << endl;
    return 0;
}

/*

	O/P
	100 100 100

*/
