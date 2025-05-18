#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "SFML View Example");
    View view(FloatRect(0.f, 0.f, 800.f, 600.f));

    RectangleShape rectangle(Vector2f(100.f, 50.f));
    rectangle.setFillColor(Color::Green);
    rectangle.setPosition(200.f, 150.f);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Black);
        window.setView(view);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}