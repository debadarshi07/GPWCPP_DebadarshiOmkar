#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    VideoMode vm(960, 540);
    RenderWindow window(vm, "Fly Image", Style :: FullScreen);

    Texture texture;
    texture.loadFromFile("soa.jpeg");

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(480, 0);
    sprite.setScale(0.5f, 0.5f);

    float speed = 100.0f;

    Clock clock;
    float dtime = clock.restart().asSeconds();
    sprite.move(0, speed * dtime);

    window.clear();
    window.draw(sprite);
    window.display();

    return 0;
}