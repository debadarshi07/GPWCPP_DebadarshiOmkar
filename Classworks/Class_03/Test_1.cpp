#include <iostream>
#include <string>
using namespace std;

class Box {
	public:
	double length, breadth, height;

	Box(double length, double breadth, double height) {
		this -> length = length;
		this -> breadth = breadth;
		this -> height = height;
	}

	double getVolume() {
		return length * breadth * height;
	}

	double getLength() {
		return length;
	}
	double setLength(double length) {
		this -> length = length;
	}

	double getBreadth() {
		return breadth;
	}
	void setBreadth(double breadth) {
		this -> breadth = breadth;
	}

	double getHeight() {
		return height;
	}
	void setHeight(double height) {
		this -> height = height;
	}
};

int main() {
	Box b(8, 5, 3);
	double vol = b.getVolume();
	cout << vol << endl;
	return 0;
}