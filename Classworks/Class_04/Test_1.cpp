#include <iostream>
#include <string>
using namespace std;

class Line {
	int length;
	
	public:
	void setLength(int l);
	int getLength();
	Line();
	Line(int length);
};

Line :: Line() {}

Line :: Line(int length) {
	this -> length = length;
	cout << "Length of line1 is: " << length << endl;
}

void Line :: setLength(int length) {
	this -> length = length;
}

int Line :: getLength() {
	return this -> length;
}

int main() {
	Line l1;
	Line l2(15);
	l1.setLength(18);

	cout << "Length of line2 is: " << l1.getLength() << endl;
}