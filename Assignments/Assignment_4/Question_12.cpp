#include <SFML/Graphics.hpp>
using namespace sf;

class PongGame {
private:
    CircleShape ball;
    Vector2f ballVelocity;
    float ballSpeed;

public:
    PongGame() {
        ball.setRadius(10.f);
        ball.setFillColor(Color::White);
        ball.setPosition(960.f, 540.f); // center of 1920x1080 window

        ballVelocity = Vector2f(-1.f, -1.f); // initial direction
        ballSpeed = 400.f;
    }

    void update(Time dt) {
        float delta = dt.asSeconds();
        ball.move(ballVelocity * ballSpeed * delta);

        // Handle ball hitting the top
        if (ball.getPosition().y <= 0) {
            ballVelocity.y = -ballVelocity.y;
        }
    }

    void draw(RenderWindow& window) {
        window.draw(ball);
    }
};
int main() {
    RenderWindow window(VideoMode(1920, 1080), "PONG Ball Top Collision");

    PongGame game;
    Clock clock;

    while (window.isOpen()) {
        Time dt = clock.restart();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        game.update(dt);

        window.clear();
        game.draw(window);
        window.display();
    }

    return 0;
}