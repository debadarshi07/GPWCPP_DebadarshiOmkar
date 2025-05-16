#include <iostream>
using namespace std;

int& getMax(int& a, int& b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 10, y = 10;
    int& maxVal = getMax(x, y);
    cout << maxVal << endl;
    maxVal = 30;
    cout << "x = " << x << ", y = " << y << endl;
    
    x = 20;
    y = 20;
    maxVal = getMax(x, y);
    cout << maxVal << endl;
    maxVal = 30;
    cout << "x = " << x << ", y = " << y << endl;
    
    x = 10;
    y = 20;
    maxVal = getMax(x, y);
    cout << maxVal << endl;
    maxVal = 30;
    cout << "x = " << x << ", y = " << y << endl;
    
    x = 20;
    y = 10;
    maxVal = getMax(x, y);
    cout << maxVal << endl;
    maxVal = 30;
    cout << "x = " << x << ", y = " << y << endl;
    
    x = 60;
    y = 40;
    maxVal = getMax(x, y);
    cout << maxVal << endl;
    maxVal = 30;
    cout << "x = " << x << ", y = " << y << endl;
    
    x = 40;
    y = 60;
    maxVal = getMax(x, y);
    cout << maxVal << endl;
    maxVal = 30;
    cout << "x = " << x << ", y = " << y << endl;
    
    
    return 0;
}
