#include <SFML/Graphics.hpp>
using namespace sf;

class Player {
private:
    Sprite sprite;
    Texture texture;
    Vector2f position;

    void centerOrigin() {
        FloatRect bounds = sprite.getLocalBounds();
        sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    }

public:
    Player(const std::string& texturePath) {
        if (!texture.loadFromFile(texturePath)) {
            throw std::runtime_error("Failed to load texture");
        }
        sprite.setTexture(texture);
        centerOrigin();
    }

    void draw(RenderWindow& window) {
        View view = window.getView();
        Vector2f center = view.getCenter();
        sprite.setPosition(center);
        window.draw(sprite);
    }

    void setScale(float x, float y) {
        sprite.setScale(x, y);
    }
};

int main() {
    RenderWindow window(VideoMode(800, 600), "Centered Player");
    Player player("player.png");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}