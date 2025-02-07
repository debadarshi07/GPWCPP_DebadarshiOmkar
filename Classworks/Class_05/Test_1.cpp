#include <iostream>
#include <string>
using namespace std;

class Box {
	double width;
	public:
	friend void print(Box box);
	void setWidth(double width) {
		this -> width = width;
	}
};

void print(Box box) {
	cout << "Width: " << box.width << endl;
}

int main() {
	Box box;
	box.setWidth(15.6);
	print(box);
	return 0;
}

/*

	=> Friend function: Function defined outside the class scope, but it has right to access the private & protected members of the class.
	=> Prototypes of friend function appear in class definition, but these are not memeber function.
	=> A friend can be a function, function template or member function, or class or class template.

*/