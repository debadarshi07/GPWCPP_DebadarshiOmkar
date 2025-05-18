class Player {
private:
    Texture texture;
    Sprite sprite;
public:
    Player();
};

Player::Player() {
    texture.loadFromFile("player.png");
    sprite.setTexture(texture);
    sprite.setOrigin(25, 25);
    sprite.setPosition(120, 234);
}