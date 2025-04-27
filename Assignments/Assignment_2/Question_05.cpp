#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    VideoMode vm(960, 540);
    RenderWindow window(vm, "Timber", Style :: FullScreen);

    while (window.isOpen()) {
        if (Keyboard :: isKeyPressed(Keyboard :: Escape)) {
            window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}