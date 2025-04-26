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
        ball.setPosition(960.f, 540.f); // center
        ballVelocity = Vector2f(-1.f, 1.f); // moving down initially
        ballSpeed = 400.f;
    }

    void update(Time dt) {
        float delta = dt.asSeconds();
        ball.move(ballVelocity * ballSpeed * delta);

        // Ball hits the top
        if (ball.getPosition().y <= 0) {
            ballVelocity.y = -ballVelocity.y;
        }

        // Ball hits the bottom
        if (ball.getPosition().y + ball.getRadius() * 2 >= 1080) {
            ballVelocity.y = -ballVelocity.y;
        }

        // Ball hits two sides
        if (ball.getPosition().x <= 0) {
            ballVelocity.x = -ballVelocity.x;
        }
    
        if (ball.getPosition().x + ball.getRadius() * 2 >= 1920) {
            ballVelocity.x = -ballVelocity.x;
        }
    }

    void draw(RenderWindow& window) {
        window.draw(ball);
    }
};

int main() {
    RenderWindow window(VideoMode(1920, 1080), "PONG Ball Bottom Collision");
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