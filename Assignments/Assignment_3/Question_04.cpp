#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {
    VideoMode(800, 600);
    RenderWindow window(vm, "Keyboard Input Example", Style :: FullScreen);

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
            std::cout << "Enter Pressed" << std::endl;
        }
        window.clear();
        window.display();
    }

    return 0;
}