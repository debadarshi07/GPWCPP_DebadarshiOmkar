#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Test {
	int **arr;
	int size;
	int index = 0;

	public:
	Test (int size) {
		arr = new int*[size];
	}

	void insertElement(int num) {
		if (index > size) {
			cout << "Array is full." << endl;
			return;
		}
		arr[index++] = new int(num);
	}

	void printElement() {
		for (int i = 0; i < index; i++) {
			cout << "Address: " << arr[i] << ", Element: " << *arr[i] << endl;
		}
	}
};

int main() {
	Test test(5);
	test.insertElement(100);
	test.insertElement(200);
	test.insertElement(300);
	
	test.printElement();
}