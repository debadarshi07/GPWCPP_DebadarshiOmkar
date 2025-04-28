#include <SFML/Graphics.hpp>
using namespace sf;

class MyRectangle {
private:
    RectangleShape rect;

public:
    MyRectangle() {
        rect.setSize(Vector2f(10.f, 10.f));
        rect.setFillColor(Color::Green);
        rect.setPosition(100.f, 100.f);
    }

    void draw(RenderWindow& window) {
        window.draw(rect);
    }
};

int main() {
    VideoMode(1920, 1080);
    RenderWindow window(vm, "Rectangle Window", Style :: FullScreen);

    MyRectangle myRect;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        myRect.draw(window);
        window.display();
    }

    return 0;
}