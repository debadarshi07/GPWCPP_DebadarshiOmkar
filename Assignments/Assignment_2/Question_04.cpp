#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    VideoMode vm(960, 540);
    RenderWindow window(vm, "Test Window", Style :: FullScreen);

    return 0;
}