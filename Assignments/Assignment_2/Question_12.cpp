#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(1920, 1080), "Red Rectangle");

    float X = 200.0f;
    float Y = 100.0f;

    RectangleShape rectangle(Vector2f(X, Y));
    rectangle.setFillColor(Color::Red);

    rectangle.setPosition((window.getSize().x - X) / 2, (window.getSize().y - Y) / 2);

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}