#include <iostream>
using namespace std;

class Box {
	private:
	double length, breadth, height;
	
	public:
	double getVolume() {
		return length * breadth * height;
	}


	double getLength() {
		return length;
	}
	void setLength(double length) {
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
	Box b;
	b.setLength(10);
	b.setBreadth(8);
	b.setHeight(5);
	double vol = b.getVolume();
	cout << "Volume: " << vol << endl;
	return 0;
}