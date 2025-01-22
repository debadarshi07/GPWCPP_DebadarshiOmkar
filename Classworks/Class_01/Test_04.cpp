#include <iostream>
using namespace std;

/*
    Uses of namespace

    1. Helps to avoid naming conflicts
    2. Make the code readable, reusable
    3. Organises the code
*/

namespace CSE {
    namespace section_2241028 {
        void printDetails(string name, long redg) {
            cout << "Name: " << name << ", Redg No: " << redg << ", Section 2241028 " << endl;
        }
    }

    namespace section_2241029 {
        void printDetails(string name, long redg) {
            cout << "Name: " << name << ", Redg No: " << redg << ", Section 2241029 " << endl;
        }
    }
}

int main() {

    namespace sec_28 = CSE :: section_2241028;
    namespace sec_29 = CSE :: section_2241029;

    sec_28 :: printDetails("Debadarshi Omkar", 2241015006);
    sec_29 :: printDetails("Sai Lochan Dash", 2241004177);

    return 0;
}