#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

class Box {
	double width, height, length;
	public:
	friend void setWidth(Box* box, double width);
	friend void setLength(Box* box, double length);
	friend void setHeight(Box* box, double height);
	friend void printVolume(Box box);
};

void setWidth(Box* box, double width) {
	box -> width = width;
}

void setLength(Box* box, double length) {
	box -> length = length;
}

void setHeight(Box* box, double height) {
	box -> height = height;
}

void printVolume(Box box) {
	cout << "Volume: " << box.width * box.height * box.length << endl;
}

int main() {
	Box box;
	setWidth(&box, 5);
	setLength(&box, 2);
	setHeight(&box, 4);
	printVolume(box);
	
	return 0;
}