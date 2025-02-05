#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Test {
	int *ptr;
	public:
	Test(int num);
	void setNumber(int num);
	int getNumber();
	void printNumber();
};

Test :: Test(int num) {
	ptr = new int(num);
}

void Test :: setNumber(int num) {
	*ptr = num;
}

int Test :: getNumber() {
	return *ptr;
}

void Test :: printNumber() {
	cout << "Number: " << *ptr << ", Address: " << ptr << endl;
}

int main() {
	Test test1(100);
	test1.setNumber(200);
	test1.printNumber();
	
	Test test2(500);
	test2.printNumber();
}