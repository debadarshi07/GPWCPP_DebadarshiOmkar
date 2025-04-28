#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

int NUM_BRANCHES = 5;
Sprite branches[NUM_BRANCHES];

int main() {
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber Game", Style :: FullScreen);

    Texture playerTexture;
    playerTexture.loadFromFile("./player.png");
    Sprite spritePlayer;
    spritePlayer.setTexture(playerTexture);
    spritePlayer.setPosition(800, 800);

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

        // Proper logic to be mentioned to track whether player has been squashed by a branch
        if (spritePlayer.getGlobalBounds().intersects(branches[NUM_BRANCHES - 1].getGlobalBounds())) {
            playerSquashed = true;
        }

        if (playerSquashed) {
            window.draw(gameOverText);
        }
        window.display();
    }

    return 0;
}