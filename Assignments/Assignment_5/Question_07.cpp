#include <SFML/Graphics.hpp>

using namespace sf;

void displayBackground(VertexArray& rVA, IntRect arena) {
    Texture backgroundSheet;
    if (!backgroundSheet.loadFromFile("background sheet.png")) {
        return;
    }

    rVA.clear();

    int tileWidth = 50;
    int tileHeight = 50;

    for (int y = arena.top; y < arena.top + arena.height; y += tileHeight) {
        for (int x = arena.left; x < arena.left + arena.width; x += tileWidth) {
            int index = (y / tileHeight) % 3;
            int textureY = index * tileHeight;

            int tileIndex = (x / tileWidth) % 3;
            int textureX = tileIndex * tileWidth;

            int vertexIndex = (x / tileWidth) * 4 + (y / tileHeight) * 4 * arena.width;

            rVA[vertexIndex].position = Vector2f(x, y);
            rVA[vertexIndex + 1].position = Vector2f(x + tileWidth, y);
            rVA[vertexIndex + 2].position = Vector2f(x + tileWidth, y + tileHeight);
            rVA[vertexIndex + 3].position = Vector2f(x, y + tileHeight);

            rVA[vertexIndex].texCoords = Vector2f(textureX, textureY);
            rVA[vertexIndex + 1].texCoords = Vector2f(textureX + tileWidth, textureY);
            rVA[vertexIndex + 2].texCoords = Vector2f(textureX + tileWidth, textureY + tileHeight);
            rVA[vertexIndex + 3].texCoords = Vector2f(textureX, textureY + tileHeight);
        }
    }

    window.draw(rVA, &backgroundSheet);
}

int main() {
    RenderWindow window(VideoMode(800, 600), "Arena Background");

    VertexArray vertexArray(Quads, 4 * 3);  // 3 tiles, each with 4 vertices

    IntRect arena(0, 0, 800, 600);  // Define the arena (full window in this case)

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        displayBackground(vertexArray, arena);
        window.display();
    }

    return 0;
}
