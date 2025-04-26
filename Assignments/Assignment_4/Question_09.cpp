#include <SFML/Graphics.hpp>
using namespace sf;

class PongGame {
private:
    RectangleShape playerBat;
    RectangleShape aiBat;
    CircleShape ball;

    Vector2f ballVelocity;
    float batSpeed;
    float ballSpeed;

public:
    void update(Time dt);
};
void PongGame::update(Time dt) {
    float deltaTime = dt.asSeconds();

    ball.move(ballVelocity * ballSpeed * deltaTime);

    Vector2f ballPos = ball.getPosition();

    if (ballPos.y <= 0 || ballPos.y + ball.getRadius() * 2 >= 1080) {
        ballVelocity.y = -ballVelocity.y;
    }

    if (ballPos.x <= 0 || ballPos.x + ball.getRadius() * 2 >= 1920) {
        ball.setPosition(960, 540);
        ballVelocity.x = -ballVelocity.x;
    }

    if (ball.getGlobalBounds().intersects(playerBat.getGlobalBounds())) {
        ballVelocity.x = std::abs(ballVelocity.x);
    }

    if (ball.getGlobalBounds().intersects(aiBat.getGlobalBounds())) {
        ballVelocity.x = -std::abs(ballVelocity.x);
    }

    if (ball.getPosition().y < aiBat.getPosition().y)
        aiBat.move(0, -batSpeed * deltaTime);
    else if (ball.getPosition().y > aiBat.getPosition().y + aiBat.getSize().y)
        aiBat.move(0, batSpeed * deltaTime);
}