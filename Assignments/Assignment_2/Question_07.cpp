#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(960, 540), "Fly Image");

    Texture texture;
    texture.loadFromFile("soa.jpeg");

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(0.5f, 0.5f);

    sprite.setPosition(480, 0);
    float speed = 100.0f;
    Clock clock;

    float dtime = clock.restart().asSeconds();
    sprite.move(0, speed * dtime);

    return 0;
}