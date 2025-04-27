#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    VideoMode vm(960, 540);
    RenderWindow window(vm, "Display SOA", Style :: FullScreen);

    Texture texture;
    texture.loadFromFile("soa.jpeg");

    Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}