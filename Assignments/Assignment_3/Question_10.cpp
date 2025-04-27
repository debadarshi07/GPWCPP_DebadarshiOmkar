#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    VideoMode(800, 600);
    RenderWindow window(vm, "SFML Sprites", Style :: FullScreen);

    Texture textureX, textureY, textureZ, textureZombie;
    textureX.loadFromFile("X.png");
    textureY.loadFromFile("Y.png");
    textureZ.loadFromFile("Z.png");
    textureZombie.loadFromFile("zombie.png");

    Sprite spriteX(textureX);
    Sprite spriteY(textureY);
    Sprite spriteZ(textureZ);
    Sprite Zombies[5];

    spriteX.setPosition(100.f, 100.f);
    spriteY.setPosition(200.f, 100.f);
    spriteZ.setPosition(300.f, 100.f);

    for (int i = 0; i < 5; i++) {
        Zombies[i].setTexture(textureZombie);
        Zombies[i].setPosition(50.f * i, 200.f + (i * 50));
    }

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        window.clear();

        window.draw(spriteX);
        window.draw(spriteY);
        window.draw(spriteZ);
        for (int i = 0; i < 5; i++) {
            window.draw(Zombies[i]);
        }

        window.display();
    }

    return 0;
}