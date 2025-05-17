#include <SFML/Graphics.hpp>
using namespace sf;

void displayBackground(VertexArray& rVA, IntRect arena) {
    const int TILE_SIZE = 50;
    const int VERTS_PER_QUAD = 4;

    int worldWidth = arena.width / TILE_SIZE;
    int worldHeight = arena.height / TILE_SIZE;

    rVA.setPrimitiveType(Quads);
    rVA.resize(worldWidth * worldHeight * VERTS_PER_QUAD);

    int currentVertex = 0;

    for (int i = 0; i < worldWidth; ++i) {
        for (int j = 0; j < worldHeight; ++j) {
            int x = i * TILE_SIZE;
            int y = j * TILE_SIZE;

            rVA[currentVertex + 0].position = Vector2f(x, y);
            rVA[currentVertex + 1].position = Vector2f(x + TILE_SIZE, y);
            rVA[currentVertex + 2].position = Vector2f(x + TILE_SIZE, y + TILE_SIZE);
            rVA[currentVertex + 3].position = Vector2f(x, y + TILE_SIZE);

            bool isBorder = (i == 0 || j == 0 || i == worldWidth - 1 || j == worldHeight - 1);
            bool isMud2Row = (j == worldHeight / 2);

            Vector2f texTL;

            if (isBorder)
                texTL = Vector2f(0, 150); // wall
            else if (isMud2Row)
                texTL = Vector2f(0, 100); // mud-2
            else
                texTL = Vector2f(0, 50);  // grass

            rVA[currentVertex + 0].texCoords = texTL;
            rVA[currentVertex + 1].texCoords = texTL + Vector2f(TILE_SIZE, 0);
            rVA[currentVertex + 2].texCoords = texTL + Vector2f(TILE_SIZE, TILE_SIZE);
            rVA[currentVertex + 3].texCoords = texTL + Vector2f(0, TILE_SIZE);

            currentVertex += VERTS_PER_QUAD;
        }
    }
}