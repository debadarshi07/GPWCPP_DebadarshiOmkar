#include <SFML/Graphics.hpp>
using namespace sf;

class Bat {
private:
    RectangleShape bat;
    float batSpeed;
    bool movingLeft;
    bool movingRight;

public:
    Bat() {
        bat.setSize(Vector2f(100.f, 5.f));
        bat.setFillColor(Color::White);
        bat.setPosition(960.f, 1050.f);
        batSpeed = 600.f;
        movingLeft = false;
        movingRight = false;
    }

    void moveLeft(Time dt) {
        if (bat.getPosition().x > 0)
            bat.move(-batSpeed * dt.asSeconds(), 0.f);

        if (bat.getPosition().x < 0)
            bat.setPosition(0, bat.getPosition().y);
    }

    void moveRight(Time dt) {
        float rightEdge = bat.getPosition().x + bat.getSize().x;
        if (rightEdge < 1920)
            bat.move(batSpeed * dt.asSeconds(), 0.f);

        if (bat.getPosition().x + bat.getSize().x > 1920)
            bat.setPosition(1920 - bat.getSize().x, bat.getPosition().y);
    }

    void stopLeft() {
        movingLeft = false;
    }

    void stopRight() {
        movingRight = false;
    }

    void update(Time dt) {
        if (movingLeft)
            moveLeft(dt);
        if (movingRight)
            moveRight(dt);
    }

    void draw(RenderWindow& window) {
        window.draw(bat);
    }

    void startLeft() {
        movingLeft = true;
    }

    void startRight() {
        movingRight = true;
    }
};