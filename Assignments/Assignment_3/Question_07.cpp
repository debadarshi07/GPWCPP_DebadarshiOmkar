#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Timber Game");

    bool logActive = false;
    Texture textureLog;
    textureLog.loadFromFile("log.png");

    Sprite logSprite(textureLog);
    logSprite.setPosition(400.f, 300.f);

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            logActive = true;
        }
        window.clear();
        if (logActive) {
            logSprite.move(5.f, 0.f);
            if (logSprite.getPosition().x > window.getSize().x) {
                logActive = false;
            }
            window.draw(logSprite);
        }
        window.display();
    }

    return 0;
}