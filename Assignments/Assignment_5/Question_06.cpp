#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(300, 300), "Tile Drawing");

    Texture texture;
    if (!texture.loadFromFile("background sheet.png"))
        return -1;

    VertexArray tiles(Quads, 3 * 4);
    Vector2f tileSize(50, 50);

    // mud-1
    tiles[0].position = Vector2f(0, 0);
    tiles[1].position = Vector2f(50, 0);
    tiles[2].position = Vector2f(50, 50);
    tiles[3].position = Vector2f(0, 50);

    tiles[0].texCoords = Vector2f(0, 0);
    tiles[1].texCoords = Vector2f(50, 0);
    tiles[2].texCoords = Vector2f(50, 50);
    tiles[3].texCoords = Vector2f(0, 50);

    // grass
    tiles[4].position = Vector2f(60, 0);
    tiles[5].position = Vector2f(110, 0);
    tiles[6].position = Vector2f(110, 50);
    tiles[7].position = Vector2f(60, 50);

    tiles[4].texCoords = Vector2f(0, 50);
    tiles[5].texCoords = Vector2f(50, 50);
    tiles[6].texCoords = Vector2f(50, 100);
    tiles[7].texCoords = Vector2f(0, 100);

    // mud-2
    tiles[8].position = Vector2f(120, 0);
    tiles[9].position = Vector2f(170, 0);
    tiles[10].position = Vector2f(170, 50);
    tiles[11].position = Vector2f(120, 50);

    tiles[8].texCoords = Vector2f(0, 100);
    tiles[9].texCoords = Vector2f(50, 100);
    tiles[10].texCoords = Vector2f(50, 150);
    tiles[11].texCoords = Vector2f(0, 150);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        window.clear();
        RenderStates states;
        states.texture = &texture;
        window.draw(tiles, states);
        window.display();
    }

    return 0;
}