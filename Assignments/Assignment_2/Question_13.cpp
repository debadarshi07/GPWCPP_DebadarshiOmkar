#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(1920, 1080), "Circle Shapes");

    float radius = 50.0f;

    CircleShape circleGreen(radius);
    circleGreen.setFillColor(Color::Green);

    CircleShape circleRed(radius);
    circleRed.setFillColor(Color::Red);

    circleGreen.setPosition(0, 0);
    CircleShape circleGreenTopRight = circleGreen;
    circleGreenTopRight.setPosition(window.getSize().radius - radius * 2, 0);
    CircleShape circleGreenBottomLeft = circleGreen;
    circleGreenBottomLeft.setPosition(0, window.getSize().y - radius * 2);
    CircleShape circleGreenBottomRight = circleGreen;
    circleGreenBottomRight.setPosition(window.getSize().radius - radius * 2, window.getSize().y - radius * 2);

    circleRed.setPosition((window.getSize().radius - radius * 2) / 2, (window.getSize().y - radius * 2) / 2);

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        window.clear();
        window.draw(circleGreen);
        window.draw(circleGreenTopRight);
        window.draw(circleGreenBottomLeft);
        window.draw(circleGreenBottomRight);

        window.draw(circleRed);

        window.display();
    }

    return 0;
}