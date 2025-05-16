#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    VertexArray quads(Quads, 10 * 10 * 4);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int index = (i * 10 + j) * 4;

            quads[index].position = Vector2f(j * 50.f, i * 50.f);
            quads[index + 1].position = Vector2f((j + 1) * 50.f, i * 50.f);
            quads[index + 2].position = Vector2f((j + 1) * 50.f, (i + 1) * 50.f);
            quads[index + 3].position = Vector2f(j * 50.f, (i + 1) * 50.f);
        }
    }

    RenderWindow window(VideoMode(800, 600), "Vertex Array with Quads");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(quads);
        window.display();
    }

    return 0;
}
