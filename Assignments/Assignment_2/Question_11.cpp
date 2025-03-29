#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(1920, 1080), "Text Centered");

    Font font;
    font.loadFromFile("KONIKAP.ttf");

    Text text("SOA UNIVERSITY", font, 100);
    text.setFillColor(Color::Red);

    FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);

    text.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}