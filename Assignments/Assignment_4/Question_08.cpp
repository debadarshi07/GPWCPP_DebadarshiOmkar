#include <SFML/Graphics.hpp>
using namespace sf;

class SelfBat {
private:
    RectangleShape bat;

public:
    SelfBat(float x, float y) {
        bat.setSize(Vector2f(100.f, 5.f));
        bat.setFillColor(Color::White);
        bat.setPosition(x, y);
    }

    void draw(RenderWindow& window) {
        window.draw(bat);
    }
};

int main() {
    RenderWindow window(VideoMode(1920, 1080), "SelfBat Demo");
    SelfBat bat(500.f, 500.f);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        bat.draw(window);
        window.display();
    }

    return 0;
}