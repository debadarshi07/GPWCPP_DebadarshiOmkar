#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Text Centered", Style :: FullScreen);

    Font font;
    font.loadFromFile("KONIKAP.ttf");

    Text text("SOA UNIVERSITY", font, 100);
    text.setFont(font);
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