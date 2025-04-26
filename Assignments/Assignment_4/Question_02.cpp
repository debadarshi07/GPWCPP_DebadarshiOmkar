#include <SFML/Graphics.hpp>
#include <sstream>
using namespace sf;

int main() {
    Font font;
    font.loadFromFile("sample.ttf");
    Text text;
    text.setFont(font);
    text.setFillColor(Color::White);
    text.setCharacterSize(75);
}