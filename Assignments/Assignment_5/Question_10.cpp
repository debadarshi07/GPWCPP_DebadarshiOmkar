#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    RenderWindow window(VideoMode(400, 300), "Key Press Test");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::W)
                    cout << "W key pressed" << endl;
                else if (event.key.code == Keyboard::Return)
                    cout << "Return key pressed" << endl;
                else if (event.key.code == Keyboard::Num0)
                    cout << "Num0 key pressed" << endl;
                else if (event.key.code == Keyboard::Num1)
                    cout << "Num1 key pressed" << endl;
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}