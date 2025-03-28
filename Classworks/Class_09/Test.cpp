#include <SFML/Graphics.hpp>
#include <sstream>
using namespace sf;

// adding branches to the tree

const int NUM_BRANCHES = 6;
Sprite branches[NUM_BRANCHES];

// location of the player/branches. The player/branch can be left or right.

enum class side {
    LEFT,
    RIGHT,
    NONE
};
side branchPositions[NUM_BRANCHES];


// Function to update the positions of the branches
void updateBranches(int);

int main() {
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "timber", Style::Fullscreen);

    Texture textureBackground;

    textureBackground.loadFromFile("../graphics/background.png");

    // Create a sprite
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    // make tree sprite
    Texture textureTree;
    textureTree.loadFromFile("../graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

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
    timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);

    Time gameTimeTotal;
    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

    bool paused = true;
    // draw text
    int score = 0;

    Text messageText;
    Text scoreText;

    // to choose the font
    Font font;
    font.loadFromFile("../fonts/KOMIKAP_.ttf");

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
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
    scoreText.setPosition(20, 20);

    // Preparing the branches
    Texture textureBranch;
    textureBranch.loadFromFile("../graphics/branch.png");

    // Set texture for each branch in the sprite
    for (int i = 0; i < NUM_BRANCHES; i++)
    {
        branches[i].setTexture(textureBranch);
        branches[i].setPosition(-2000, -2000);

        // Set sprite origin
        // We can rotate the branches without changing the position
        branches[i].setOrigin(220, 20);
    }
    
    // Update branches
    updateBranches(1);
    updateBranches(2);
    updateBranches(3);
    updateBranches(4);
    updateBranches(5);
    
    
    Texture texturePlayer;
    texturePlayer.loadFromFile("../graphics/player.png");
    Sprite spritePlayer;
    spritePlayer.setTexture(texturePlayer);
    spritePlayer.setPosition(580, 720);
    
    // Put the player on the lfe hand side
    side playerSide = side :: LEFT;
    
    // Prepare gravestone
    Texture textureRIP;
    textureRIP.loadFromFile("../graphics/rip.png");
    Sprite spriteRIP;
    spriteRIP.setTexture(textureRIP);
    spriteRIP.setPosition(600, 860);
    
    // Prepare axe
    Texture textureAxe;
    textureAxe.loadFromFile("..graphics/axe.png");
    Sprite spriteAxe;
    spriteAxe.setTexture(textureAxe);
    spriteAxe.setPosition(590, 750);
    

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {

            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            paused = false;
            score = 0;
            timeRemaining = 6;
        }

        if (!paused)
        {
            // Updating the scene
            Time dt = clock.restart();

            // subtract from the amount of time remaining
            timeRemaining = timeRemaining - dt.asSeconds();

            // size up the timebar
            timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));

            if (timeRemaining <= 0.0f)
            {
                paused = true;

                // change the message shown to the player
                messageText.setString("Out of Time !!");

                // reposition the text based on the new size
                FloatRect textRect = messageText.getLocalBounds();
                messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

                messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
            }

            if (!beeActive)
            {
                srand((int)time(0));
                beeSpeed = (rand() % 200) + 200;

                // deciding the height of the bee
                srand((int)time(0) * 10);
                float height = (rand() % 500) + 500;
                spriteBee.setPosition(2000, height);
                beeActive = true;
            }
            else
            {
                spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);

                if (spriteBee.getPosition().x < -100)
                {
                    beeActive = false;
                }
            }

            // managing the cloud to blow

            // cloud1
            if (!cloud1Active)
            {
                srand((int)time(0) * 10);
                cloud1Speed = (rand() % 200);

                // height of the cloud
                srand((int)time(0) * 10);
                float height = (rand() % 150);
                spriteCloud1.setPosition(-200, height);
                cloud1Active = true;
            }
            else
            {
                spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);
                if (spriteCloud1.getPosition().x > 1920)
                {
                    cloud1Active = false;
                }
            }

            // cloud2
            if (!cloud2Active)
            {
                srand((int)time(0) * 20);
                cloud2Speed = (rand() % 200);

                // height of the cloud
                srand((int)time(0) * 20);
                float height = (rand() % 300) - 150;
                spriteCloud2.setPosition(-200, height);
                cloud2Active = true;
            }
            else
            {
                spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);
                if (spriteCloud2.getPosition().x > 1920)
                {
                    cloud2Active = false;
                }
            }

            // cloud 3
            if (!cloud3Active)
            {
                srand((int)time(0) * 30);
                cloud3Speed = (rand() % 200);

                // height of the cloud
                srand((int)time(0) * 30);
                float height = (rand() % 450) - 150;
                spriteCloud3.setPosition(-200, height);
                cloud3Active = true;
            }
            else
            {
                spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);
                if (spriteCloud3.getPosition().x > 1920)
                {
                    cloud3Active = false;
                }
            }
            // update the score Text
            std::stringstream ss;
            ss << "Score = " << score;
            scoreText.setString(ss.str());

            // Update the branch sprite
            for (int i = 0; i < NUM_BRANCHES; i++)
            {
                float height = i * 150;
                if (branchPositions[i] == side :: LEFT) {
                	// move the sprite to left side
                	branches[i].setPosition(610, height);
                	// flip the sprite to other side by 180 degree
                	branches[i].setRotation(180);
                } else if (branchPositions[i] == side :: RIGHT) {
                	// Move the sprite to the right side
                	branches[i].setPosition(1330, height);
                	branches[i].setRotation(0);
                } else {
                	// hide the branches
                	branches[i].setPosition(3000, height);
                	
                }
                
                
            }
        }

        //**************************************************//
        //                     Drawing board			    //
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
        if (paused)
        {
            window.draw(messageText);
        }
        window.draw(spritePlayer);
        window.draw(spriteRIP);
        window.draw(spriteAxe);
        window.display();
    }
}


// Function body to update branches
void updateBranches(int seed) {
	// move all branches to one place
	for (int j = NUM_BRANCHES - 1; j > 0; j--) {
		branchPositions[j] = branchPositions[j - 1];
	}
	// Move the branches to position 0
	// Left, right, none
	srand((int)time(0) + seed);
	int r = (rand() % 5);
	
	switch (r) {
		case 0:
			branchPositions[0] = side :: LEFT;
			break;
			
		case 1:
			branchPositions[0] = side :: RIGHT;
			break;
			
		default:
			branchPositions[0] = side :: NONE;
			break;
	}
}
