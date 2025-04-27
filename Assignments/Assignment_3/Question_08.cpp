#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

int main() {
    VideoMode(800, 600);
    RenderWindow window(vm, "Timber Game", Style :: FullScreen);

    Font font;
    font.loadFromFile("arial.ttf");

    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Player Expired - Game End");
    gameOverText.setCharacterSize(40);
    gameOverText.setFillColor(Color::Red);

    FloatRect textRect = gameOverText.getLocalBounds();
    gameOverText.setOrigin(textRect.width / 2, textRect.height / 2);
    gameOverText.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    bool playerSquashed = false;

    while (window.isOpen()) {
        window.clear();

        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            playerSquashed = true;
        }

        if (playerSquashed) {
            window.draw(gameOverText);
        }
        window.display();
    }

    return 0;
}