#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    IntRect rect(100, 100, 400, 300);
    View viewFromRect(FloatRect(rect.left, rect.top, rect.width, rect.height));

    Vector2f center(300.f, 250.f);
    Vector2f size(400.f, 300.f);
    View viewFromCenter(center, size);

    return 0;
}