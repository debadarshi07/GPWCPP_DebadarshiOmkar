#include <SFML/Graphics.hpp>
#include <sstream>
using namespace sf;

// adding branches to the tree

const int NUM_BRANCHES = 6;
Sprite branches[NUM_BRANCHES];

// location of the player/branches. The player/branches can be left or right

enum class side {
     LEFT,
     RIGHT,
     NONE
};
side branchPositions[NUM_BRANCHES];

// function to update the positions of the branches
void updateBranches(int seed);

int main() {
     VideoMode vm(1920, 1080);
     RenderWindow window(vm, "timber", Style::Fullscreen);

     // make background sprite
     Texture textureBackground;
     textureBackground.loadFromFile("../graphics/background.png");
     Sprite spriteBackground;
     spriteBackground.setTexture(textureBackground);
     spriteBackground.setPosition(0, 0);

     // make tree sprite
     Texture textureTree;
     textureTree.loadFromFile("../graphics/tree.png");
     Sprite spriteTree;
     spriteTree.setTexture(textureTree);
     spriteTree.setPosition(810, 0);

     // make bee sprite
     Texture textureBee;
     textureBee.loadFromFile("../graphics/bee.png");
     Sprite spriteBee;
     spriteBee.setTexture(textureBee);
     spriteBee.setPosition(0, 800);

     bool beeActive = false;
     float beeSpeed = 0.0f;

     // making clouds
     Texture textureCloud;
     textureCloud.loadFromFile("../graphics/cloud.png");

     Sprite spriteCloud1;
     Sprite spriteCloud2;
     Sprite spriteCloud3;
     spriteCloud1.setTexture(textureCloud);
     spriteCloud2.setTexture(textureCloud);
     spriteCloud3.setTexture(textureCloud);

     spriteCloud1.setPosition(0, 0);
     spriteCloud2.setPosition(0, 250);
     spriteCloud3.setPosition(0, 500);

     bool cloud1Active = false;
     bool cloud2Active = false;
     bool cloud3Active = false;

     // how fast is the cloud
     float cloud1Speed = 0.0f;
     float cloud2Speed = 0.0f;
     float cloud3Speed = 0.0f;

     Clock clock;
     // adding the time bar
     RectangleShape timeBar;
     float timeBarStartWidth = 400;
     float timeBarHeight = 80;
     timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
     timeBar.setFillColor(Color::Red);
     timeBar.setPosition((1920 - timeBarStartWidth) / 2, 980);

     Time gameTimeTotal;
     float timeRemaining = 6.0f;
     float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

     bool paused = true;
     // draw text
     int score = 0;

     // to choose the font
     Font font;
     font.loadFromFile("../fonts/KOMIKAP_.ttf");

     Text messageText;
     Text scoreText;

     // setting font for our message
     messageText.setFont(font);
     scoreText.setFont(font);

     // assign the actual message
     messageText.setString("Press enter to start !");
     scoreText.setString("Score = 0");

     // setting the character size
     messageText.setCharacterSize(75);
     scoreText.setCharacterSize(100);

     // setting font color
     messageText.setFillColor(Color::White);
     scoreText.setFillColor(Color::White);

     // setting positions of texts
     FloatRect textRect = messageText.getLocalBounds();
     messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
     messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
     scoreText.setPosition(20, 20);

     // preparing the branches
     Texture textureBranch;
     textureBranch.loadFromFile("../graphics/branch.png");

     // set texture for each branch in the sprite
     for (int i = 0; i < NUM_BRANCHES; i++) {
          branches[i].setTexture(textureBranch);
          branches[i].setPosition(-2000, -2000);

          // set sprite origin
          // we can rotate the branches without changing the position
          branches[i].setOrigin(220, 20);
     }
     // update branches
     updateBranches(1);
     updateBranches(2);
     updateBranches(3);
     updateBranches(4);
     updateBranches(5);
     // preparing the player
     Texture texturePlayer;
     texturePlayer.loadFromFile("../graphics/player.png");
     Sprite spritePlayer;
     spritePlayer.setTexture(texturePlayer);
     spritePlayer.setPosition(580, 720);

     // put the player on the left hand side
     side playerSide = side::LEFT;

     // prepare gravestone
     Texture textureRIP;
     textureRIP.loadFromFile("../graphics/rip.png");
     Sprite spriteRIP;
     spriteRIP.setTexture(textureRIP);
     spriteRIP.setPosition(600, 860);

     // prepare axe
     Texture textureAxe;
     textureAxe.loadFromFile("../graphics/axe.png");
     Sprite spriteAxe;
     spriteAxe.setTexture(textureAxe);
     spriteAxe.setPosition(700, 830);

     // align the axe with the treee
     const float AXE_POSITION_LEFT = 700;
     const float AXE_POSITION_RIGHT = 1075;

     // FLYING LOG
     Texture textureLog;
     textureLog.loadFromFile("../graphics/log.png");
     Sprite spriteLog;
     spriteLog.setTexture(textureLog);
     spriteLog.setPosition(810, 720);

     // variables related to log
     bool logActive = false;
     float logSpeedX = 1000;
     float logSpeedY = -1500;
     // control the player input
     bool acceptInput = false;

     while (window.isOpen()) {
          Event event;
          while (window.pollEvent(event)) {
               if (event.type == Event::KeyReleased && !paused) {
                    acceptInput = true;

                    // hide the axe
                    spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
               }
          }

          if (Keyboard::isKeyPressed(Keyboard::Escape)) {
               window.close();
          }
          if (Keyboard::isKeyPressed(Keyboard::Return)) {
               paused = false;
               score = 0;
               timeRemaining = 6;

               // make branches disappear initially
               for (int i = 1; i < NUM_BRANCHES; i++) {
                    branchPositions[i] = side::NONE;
               }

               // make the grave stone hidden
               spriteRIP.setPosition(675, 2000);

               // place the player in correct position
               spritePlayer.setPosition(675, 660);

               acceptInput = true;
          }
          if (acceptInput) {

               if (Keyboard::isKeyPressed(Keyboard::Right)) {

                    playerSide = side::RIGHT;
                    score++;

                    // time remaining will be increased
                    timeRemaining += (2 / score) + 0.15;

                    spriteAxe.setPosition(AXE_POSITION_RIGHT, spriteAxe.getPosition().y);
                    spritePlayer.setPosition(1200, 720);

                    updateBranches(score);
                    spriteLog.setPosition(810, 720);
                    logSpeedX = -5000;
                    logActive = true;

                    acceptInput = false;
               }

               if (Keyboard::isKeyPressed(Keyboard::Left)) {

                    playerSide = side::LEFT;
                    score++;

                    // time remaining will be increased
                    timeRemaining += (2 / score) + 0.15;

                    spriteAxe.setPosition(AXE_POSITION_LEFT, spriteAxe.getPosition().y);
                    spritePlayer.setPosition(580, 720);

                    updateBranches(score);
                    spriteLog.setPosition(810, 720);
                    logSpeedX = 5000;
                    logActive = true;

                    acceptInput = false;
               }
          }
          if (!paused) {
               // Updating the scene
               Time dt = clock.restart();

               // subtract from the amount of time remaining
               timeRemaining -= dt.asSeconds();

               // size up the timebar
               timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));

               if (timeRemaining <= 0.0f) {
                    paused = true;

                    // change the message shown to the player
                    messageText.setString("Out of Time !!");

                    // reposition the text based on the new size
                    FloatRect textRect = messageText.getLocalBounds();
                    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

                    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
               }

               if (!beeActive) {
                    srand((int)time(0));
                    beeSpeed = (rand() % 200) + 200;

                    // deciding the height of the bee
                    srand((int)time(0) * 10);
                    float height = (rand() % 500) + 500;
                    spriteBee.setPosition(2000, height);
                    beeActive = true;
               }
               else {
                    spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);

                    if (spriteBee.getPosition().x < -100) {
                         beeActive = false;
                    }
               }

               // managing the cloud to blow

               // cloud1
               if (!cloud1Active) {
                    srand((int)time(0) * 10);
                    cloud1Speed = (rand() % 200);

                    // height of the cloud
                    srand((int)time(0) * 10);
                    float height = (rand() % 150);
                    spriteCloud1.setPosition(-200, height);
                    cloud1Active = true;
               }
               else {
                    spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);
                    if (spriteCloud1.getPosition().x > 1920) {
                         cloud1Active = false;
                    }
               }

               // cloud2
               if (!cloud2Active) {
                    srand((int)time(0) * 20);
                    cloud2Speed = (rand() % 200);

                    // height of the cloud
                    srand((int)time(0) * 20);
                    float height = (rand() % 300) - 150;
                    spriteCloud2.setPosition(-200, height);
                    cloud2Active = true;
               }
               else {
                    spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);
                    if (spriteCloud2.getPosition().x > 1920) {
                         cloud2Active = false;
                    }
               }

               // cloud 3
               if (!cloud3Active) {
                    srand((int)time(0) * 30);
                    cloud3Speed = (rand() % 200);

                    // height of the cloud
                    srand((int)time(0) * 30);
                    float height = (rand() % 450) - 150;
                    spriteCloud3.setPosition(-200, height);
                    cloud3Active = true;
               }
               else {
                    spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);
                    if (spriteCloud3.getPosition().x > 1920) {
                         cloud3Active = false;
                    }
               }
               // update the score Text
               std::stringstream ss;
               ss << "Score = " << score;
               scoreText.setString(ss.str());

               // update the branch sprite
               for (int i = 0; i < NUM_BRANCHES; i++) {
                    float height = i * 150;

                    if (branchPositions[i] == side::LEFT) {
                         // move the sprite to left side
                         branches[i].setPosition(610, height);
                         // flip the sprite to other side by 180 degree
                         branches[i].setRotation(180);
                    }
                    else if (branchPositions[i] == side::RIGHT) {
                         // MOVE THE SPRITE TO THE RIGHT SIDE
                         branches[i].setPosition(1330, height);
                         branches[i].setRotation(0);
                    }
                    else {
                         // hide the branches
                         branches[i].setPosition(3000, height);
                    }
               }

               if (logActive) {
                    spriteLog.setPosition(spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()), spriteLog.getPosition().y + (logSpeedY * dt.asSeconds()));

                    if (spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000) {
                         logActive = false;
                         spriteLog.setPosition(810, 720);
                    }
               }

               if (branchPositions[5] == playerSide) {
                    // death
                    paused = true;
                    acceptInput = false;
                    spriteRIP.setPosition(525, 768);

                    // hide player
                    spritePlayer.setPosition(2000, 660);

                    // change text message
                    messageText.setString("Killed by Tree !!!");

                    FloatRect textRect = messageText.getLocalBounds();
                    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

                    messageText.setPosition(1910 / 2.0f, 1000 / 2.0f);
               }
          }

           //*************************************************//
          //                   Drawing board                 //
         //*************************************************//

          window.clear();
          window.draw(spriteBackground);
          window.draw(spriteTree);
          window.draw(spriteBee);
          window.draw(spriteCloud1);
          window.draw(spriteCloud2);
          window.draw(spriteCloud3);

          // drawing the branches
          for (int i = 0; i < NUM_BRANCHES; i++) {
               window.draw(branches[i]);
          }
          window.draw(scoreText);
          window.draw(timeBar);
          if (paused) {
               window.draw(messageText);
          }
          window.draw(spritePlayer);
          window.draw(spriteRIP);
          window.draw(spriteAxe);

          window.display();
     }
}

// function to update branches
void updateBranches(int seed) {
     // move all branches to one place
     for (int j = NUM_BRANCHES - 1; j > 0; j--) {
          branchPositions[j] = branchPositions[j - 1];
     }
     // move new branches to position 0
     // left right, none
     srand((int)time(0) + seed);
     int r = (rand() % 5);

     switch (r) {
     case 0:
          branchPositions[0] = side::LEFT;
          break;
     case 1:
          branchPositions[0] = side::RIGHT;
          break;
     default:
          branchPositions[0] = side::NONE;
          break;
     }
}