#include <SFML/Graphics.hpp>

using namespace sf;

class Zombie {
private:
    Sprite sprite;
    Texture texture;
    int type;

public:
    void spawn(float startX, float startY, int type, int seed) {
        this->type = type;
        srand(seed);

        switch (type) {
            case 0:
                texture.loadFromFile("graphics/bloater.png");
                break;
            case 1:
                texture.loadFromFile("graphics/chaser.png");
                break;
            case 2:
                texture.loadFromFile("graphics/crawler.png");
                break;
            default:
                texture.loadFromFile("graphics/bloater.png");
                break;
        }

        sprite.setTexture(texture);
        sprite.setPosition(startX, startY);
    }

    void draw(RenderWindow& window) {
        window.draw(sprite);
    }
};