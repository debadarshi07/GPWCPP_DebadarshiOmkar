#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Event Example");

    Event event;

    while (window.isOpen()) {
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