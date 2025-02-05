#include <iostream>
using namespace std;

class Line {
	int *ptr;
	
	public:
	void setLength(int length);
	int getLength();
	Line();		// Empty Constructor
	Line(int length);		// Parametrized Constructor
	Line(const Line &obj);		// Copy Constructor
	~Line();		// Deconstructor
};

Line :: Line() {
	ptr = new int;
	*ptr = 10;
	cout << "Empty constructor is being invoked." << endl;
}

Line :: Line(int length) {
	ptr = new int;
	*ptr = length;
	cout << "Parametrized constructor is being invoked." << endl;
}

Line :: Line(const Line &obj) {
	ptr = new int;
	*ptr = *obj.ptr;
	cout << "Copy constructor is being invoked." << endl;
}

Line :: ~Line() {
	delete ptr;
}

int Line :: getLength(void) {
	return *ptr;
}

void Line :: setLength(int length) {
	*ptr = length;
}

int main() {
	Line l1;
	Line l2(30);
	Line l3(l2);

	cout << "Length of l1: " << l1.getLength() <<endl;
	cout << "Length of l2: " << l2.getLength() <<endl;
	cout << "Length of l3: " << l3.getLength() <<endl;

	l2.setLength(50);

	cout << "Length of l1: " << l1.getLength() <<endl;
	cout << "Length of l2: " << l2.getLength() <<endl;
	cout << "Length of l3: " << l3.getLength() <<endl;
}