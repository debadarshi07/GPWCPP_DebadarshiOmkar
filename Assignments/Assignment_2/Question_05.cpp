#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(960, 540), "Timber");

    while (window.isOpen()) {
        if (Keyboard :: isKeyPressed(Keyboard :: Escape)) {
            window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}