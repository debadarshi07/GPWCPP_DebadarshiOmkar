#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 5};
    cout << vec1[0] << endl;

    vector<int> vec2(5, 2);
    for (int i = 0; i < 5; i++) {
        cout << vec2[i] << "\t";
    }



    return 0;
}