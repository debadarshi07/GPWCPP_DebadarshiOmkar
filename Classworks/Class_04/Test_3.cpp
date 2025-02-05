#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
	int *ptr1 = new int;
	*ptr1 = 20;
	int *ptr2 = new int;
	*ptr2 = 50;
	int *ptr3 = new int;
	*ptr3 = 100;

	int *arr[] = {ptr1, ptr2, ptr3};
	
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << arr[i] << ": " << *arr[i] << endl;
	}
}