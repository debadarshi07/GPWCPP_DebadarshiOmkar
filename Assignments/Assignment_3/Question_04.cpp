#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Keyboard Input Example");

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
            std::cout << "Enter Pressed" << std::endl;
        }
        window.clear();
        window.display();
    }

    return 0;
}