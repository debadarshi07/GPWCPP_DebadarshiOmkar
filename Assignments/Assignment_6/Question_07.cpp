#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

enum class GameState {
    GAME_OVER,
    LEVELING_UP,
    PLAYING,
    PAUSED
};

int main() {
    RenderWindow window(VideoMode(800, 600), "Game State Transition");

    GameState currentState = GameState::GAME_OVER;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed) {
                if (currentState == GameState::GAME_OVER && event.key.code == Keyboard::Enter) {
                    currentState = GameState::LEVELING_UP;
                    cout << "State changed to LEVELING_UP" << endl;
                }
                else if (currentState == GameState::LEVELING_UP && event.key.code == Keyboard::Num1) {
                    currentState = GameState::PLAYING;
                    cout << "State changed to PLAYING" << endl;
                }
                else if (currentState == GameState::PLAYING && event.key.code == Keyboard::Enter) {
                    currentState = GameState::PAUSED;
                    cout << "State changed to PAUSED" << endl;
                }
                else if (currentState == GameState::PAUSED && event.key.code == Keyboard::Enter) {
                    currentState = GameState::PLAYING;
                    cout << "State changed to PLAYING" << endl;
                }
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}