#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(960, 540), "Fly Image");

    Texture texture;
    texture.loadFromFile("soa.jpeg");

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(0.5f, 0.5f);

    sprite.setPosition(0, 270);
    float speed = 100.0f;
    Clock clock;

    float dtime = clock.restart().asSeconds();
    sprite.move(speed * dtime, 0);

    return 0;
}