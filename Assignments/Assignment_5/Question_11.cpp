#include <SFML/Graphics.hpp>
using namespace sf;
enum GameState { ON, OFF };

int main() {
    RenderWindow window(VideoMode(600, 400), "Game State Toggle");

    Texture playerTexture;
    playerTexture.loadFromFile("player.png");

    Texture bloaterTexture;
    bloaterTexture.loadFromFile("bloater.png");

    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(100, 100);

    Sprite bloaterSprite;
    bloaterSprite.setTexture(bloaterTexture);
    bloaterSprite.setPosition(100, 100);

    GameState state = ON;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Return) {
                if (state == ON)
                    state = OFF;
                else
                    state = ON;
            }
        }

        window.clear(Color::Red);

        if (state == ON)
            window.draw(playerSprite);
        else
            window.draw(bloaterSprite);

        window.display();
    }

    return 0;
}