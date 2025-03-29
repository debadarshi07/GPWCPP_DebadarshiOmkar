#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(960, 540), "Display SOA");

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