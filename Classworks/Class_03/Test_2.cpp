#include <iostream>
using namespace std;

class Box {
	public:
	double length, breadth, height;
	
	void setLength(double length);
	double getLength();
	
	void setBreadth(double breadth);
	double getBreadth();
	
	void setHeight(double height);
	double getHeight();
	
	double getVolume();
};

void Box :: setLength(double length) {
	this -> length = length;
}
void Box :: setBreadth(double breadth) {
	this -> breadth = breadth;
}
void Box :: setHeight(double height) {
	this -> height = height;
}

double Box :: getLength() {
	return length;
}
double Box :: getBreadth() {
	return breadth;
}
double Box :: getHeight() {
	return height;
}
double Box :: getVolume() {
	return length * breadth * height;
}

int main() {
	Box b;
	b.setLength(10);
	b.setBreadth(8);
	b.setHeight(5);
	double vol = b.getVolume();
	cout << "Volume: " << vol << endl;
	return 0;
}