#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "SFML Tile Example");

    Texture backgroundSheet;
    if (!backgroundSheet.loadFromFile("background sheet.png")) {
        return -1;
    }

    VertexArray tiles(Quads, 4 * 3);

    tiles[0].position = Vector2f(100.f, 100.f);
    tiles[1].position = Vector2f(150.f, 100.f);
    tiles[2].position = Vector2f(150.f, 150.f);
    tiles[3].position = Vector2f(100.f, 150.f);

    tiles[0].texCoords = Vector2f(0.f, 0.f);
    tiles[1].texCoords = Vector2f(50.f, 0.f);
    tiles[2].texCoords = Vector2f(50.f, 50.f);
    tiles[3].texCoords = Vector2f(0.f, 50.f);

    tiles[4].position = Vector2f(200.f, 100.f);
    tiles[5].position = Vector2f(250.f, 100.f);
    tiles[6].position = Vector2f(250.f, 150.f);
    tiles[7].position = Vector2f(200.f, 150.f);

    tiles[4].texCoords = Vector2f(0.f, 50.f);
    tiles[5].texCoords = Vector2f(50.f, 50.f);
    tiles[6].texCoords = Vector2f(50.f, 100.f);
    tiles[7].texCoords = Vector2f(0.f, 100.f);

    tiles[8].position = Vector2f(300.f, 100.f);
    tiles[9].position = Vector2f(350.f, 100.f);
    tiles[10].position = Vector2f(350.f, 150.f);
    tiles[11].position = Vector2f(300.f, 150.f);

    tiles[8].texCoords = Vector2f(0.f, 100.f);
    tiles[9].texCoords = Vector2f(50.f, 100.f);
    tiles[10].texCoords = Vector2f(50.f, 150.f);
    tiles[11].texCoords = Vector2f(0.f, 150.f);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(tiles, &backgroundSheet);
        window.display();
    }

    return 0;
}
