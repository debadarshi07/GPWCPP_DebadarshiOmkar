#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    VideoMode vm(800, 600);
    RenderWindow window(vm, "Timber Game", Style::FullScreen);

    bool logActive = false;
    Texture textureLog;
    textureLog.loadFromFile("log.png");

    Sprite logSprite(textureLog);
    logSprite.setPosition(400.f, 300.f);

    while (window.isOpen()) {
        if ((Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::Right))) {
            logActive = true;
        }

        window.clear();

        if (logActive) {
            logSprite.move(1000.f, 800.f);
            if (logSprite.getPosition().x > window.getSize().x || logSprite.getPosition().y > window.getSize().y) {
                logActive = false;
            }
            window.draw(logSprite);
        }
        window.display();
    }

    return 0;
}