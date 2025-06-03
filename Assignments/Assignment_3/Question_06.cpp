#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int original_array[10];
    for (int i = 0; i < 10; i++) {
        original_array[i] = rand() % 20 + 1;
    }

    cout << "Original Array: ";
    for (int i = 0; i < 10; i++) {
        cout << original_array[i] << " ";
    }
    cout << endl;

    for (int i = 9; i >= 2; i--) {
        original_array[i] = original_array[i - 2];
    }

    original_array[0] = rand() % 11 + 20;
    original_array[1] = rand() % 11 + 20;

    cout << "Shifted Array: ";
    for (int i = 0; i < 10; i++) {
        cout << original_array[i] << " ";
    }
    cout << endl;

    return 0;
}