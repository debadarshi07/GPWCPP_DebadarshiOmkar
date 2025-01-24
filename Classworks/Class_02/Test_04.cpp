#include <iostream>
using namespace std;

class Forest {
	private:
		int trees, birds, man;

	public:
		void standing() {
			cout << "Tree is standing.\n";
		}

		void moving() {
			cout << "Man is moving.\n";
		}

		void flying() {
			cout << "Bird is flying.\n";
		}
};

int main() {
	Forest tree, bird, man;

	man.moving();
	tree.standing();
	bird.flying();
}