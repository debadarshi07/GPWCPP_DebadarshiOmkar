#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;

int main() {
    VideoMode(800, 600);
    RenderWindow window(vm, "Timber Game - Out of Time Sound", Style :: FullScreen);

    SoundBuffer buffer;
    buffer.loadFromFile("out_of_time_sound.wav");

    Sound sound;
    sound.setBuffer(buffer);

    bool outOfTime = false;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::O) {
                outOfTime = true;
            }
        }

        if (outOfTime) {
            sound.play();
            outOfTime = false;
        }

        window.clear();
        window.display();
    }

    return 0;
}