class Player {
private:
    Sprite sprite;

public:
    void spawn(float startX, float startY) {
        sprite.setPosition(startX, startY);
    }

    void draw(RenderWindow& window) {
        window.draw(sprite);
    }

    void setTexture(Texture& texture) {
        sprite.setTexture(texture);
    }
};

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

int main() {
    RenderWindow window(VideoMode(800, 800), "Multi-Player Arena");

    Texture playerTexture;
    playerTexture.loadFromFile("graphics/player.png");

    vector<Player> players(5);
    for (auto& player : players)
        player.setTexture(playerTexture);

    // Define spawn positions (4 corners + center)
    Vector2f positions[] = {
        Vector2f(0, 0),          // Top-left
        Vector2f(800 - 50, 0),   // Top-right
        Vector2f(0, 800 - 50),   // Bottom-left
        Vector2f(800 - 50, 800 - 50), // Bottom-right
        Vector2f(400 - 25, 400 - 25)  // Center
    };

    for (int i = 0; i < 5; ++i) {
        players[i].spawn(positions[i].x, positions[i].y);
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        // Draw all players
        for (auto& player : players)
            player.draw(window);

        window.display();
    }

    return 0;
}