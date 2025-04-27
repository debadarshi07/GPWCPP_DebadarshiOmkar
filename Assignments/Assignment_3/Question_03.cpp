#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {
    VideoMode vm(800, 600);
    RenderWindow window(vm, "Event Example", Style :: FullScreen);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::KeyPressed) {
                std::cout << "KeyPressed Detected" << std::endl;
            }
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.display();
    }

    return 0;
}