#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 5};
    cout << vec1[0] << endl;

    vector<int> vec2(5, 2);
    for (int i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << "\t";
    }

    cout << endl;

    // for-each loop
    for (int element : vec2) {
        cout << element * 2 << "\t";
    }

    cout << endl;

    // Enters element at the end
    vec2.push_back(25);
    for (int element : vec2) {
        cout << element << "\t";
    }

    cout << endl;

    // Removes the last element
    vec2.pop_back();
    for (int element : vec2) {
        cout << element << "\t";
    }

    cout << endl;

    vector<int> vec3 = {1, 2, 3, 4, 5, 6};

    cout << "\nFront element of vec3: " << vec3.front() << endl;
    cout << "Back element of vec3: " << vec3.back() << endl;
    cout << "Element at index 3 of vec3: " << vec3.at(3) << endl;

    cout << "\nSize of vec3: " << vec3.size() << endl;
    cout << "Capacity of vec3: " << vec3.capacity() << endl;

    vec3.push_back(7);
    cout << "\nSize of vec3: " << vec3.size() << endl;
    cout << "Capacity of vec3: " << vec3.capacity() << endl;
    

    return 0;
}