#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;

int main() {
    // create a video mode object
    VideoMode vm(1920, 1080);
    // to create and open a window 
    RenderWindow window(vm, "Timber", Style::Fullscreen);
	
    // create an object that will hold a graphics on gpu
    Texture textureBackground; 
    
    // load graphics in the texture
    textureBackground.loadFromFile("../graphics/background.png");
    
    // Create a sprite
    Sprite spriteBackground;
    
    // attach texture to sprite
    spriteBackground.setTexture(textureBackground);
    
    // set the spritebackground position to cover the screen
    spriteBackground.setPosition(0, 0);
    
    // make a tree sprite
    Texture textureTree;
    textureTree.loadFromFile("../graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);
    
    // adding bee in the spritesheet
    Texture textureBee;
    textureBee.loadFromFile("../graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(2000, 800);
    
    // is the bee currently moving
    bool beeActive = false;
    
    // how fast the bee can fly
    float beeSpeed = 0.0f;
    
    // make 3 cloud sprites in 1 texture
    Texture textureCloud;
    
    // load 1 new texture
    textureCloud.loadFromFile("../graphics/cloud.png");
    
    // 3 new sprites with the same texture
    Sprite spriteCloud1, spriteCloud2, spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);
    
    // position of cloud at left side of screen at different position
    spriteCloud1.setPosition(-200, 0);
    spriteCloud2.setPosition(-500, 250);
    spriteCloud3.setPosition(-800, 500);
    
    // are the clouds currently moving
    bool cloud1Active = false, cloud2Active = false, cloud3Active = false;
    
    // how fast the cloud should be moving
    float cloud1Speed = 0.0f, cloud2Speed = 0.0f, cloud3Speed = 0.0f;
	
    // Clock to track time
    Clock clock;
    srand(static_cast<unsigned>(time(0)));
    
    while (window.isOpen()) {
        /* Handle the player input */
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
		
        /* Update the scene */
        Time dt = clock.restart();
		
        // Manage the bee movement
        if (!beeActive) {
            srand((int)time(0));
            beeSpeed = (rand() % 200) + 200;
            srand((int) time(0) * 10);
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);
            beeActive = true;
        } else {
        	spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
        	if (spriteBee.getPosition().x < -100) {
        		beeActive = false;
        	}
        }
		
        // Manage cloud 1 movement
        if (!cloud1Active) {
        	srand((int) time(0) * 20);
        	cloud1Speed = (rand() % 100);
        	
        	srand((int)time(0) * 20);
        	float height = (rand() % 150);
        	spriteCloud1.setPosition(-200, height);
        	cloud1Active = true;
        } else {
        	spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);
        	if (spriteCloud1.getPosition().x > 1920) {
        		cloud1Active = false;
        	}
        }
		
        // Manage cloud 2 movement
        if (!cloud2Active) {
        	srand((int) time(0) * 25);
        	cloud2Speed = (rand() % 150);
        	
        	srand((int)time(0) * 20);
        	float height = (rand() % 300);
        	spriteCloud2.setPosition(-200, height);
        	cloud2Active = true;
        } else {
        	spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);
        	if (spriteCloud2.getPosition().x > 1920) {
        		cloud2Active = false;
        	}
        }
		
        // Manage cloud 3 movement
        if (!cloud3Active) {
        	srand((int) time(0) * 30);
        	cloud3Speed = (rand() % 200);
        	
        	srand((int)time(0) * 30);
        	float height = (rand() % 50);
        	spriteCloud3.setPosition(-200, height);
        	cloud3Active = true;
        } else {
        	spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);
        	if (spriteCloud3.getPosition().x > 1920) {
        		cloud3Active = false;
        	}
        }
		
        /* Draw the scene */
        window.clear();
        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.display();
    }
	
    return 0;
}
