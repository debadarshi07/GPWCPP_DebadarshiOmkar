#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int randomNumber = rand() % 21 + 80; // (100 - 80 + 1) = 21
    cout << "Random number between 80 and 100: " << randomNumber << endl;

    return 0;
}