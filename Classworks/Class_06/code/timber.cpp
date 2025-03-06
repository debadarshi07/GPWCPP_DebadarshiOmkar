#include<SFML/Graphics.hpp>
using namespace sf;

int main(){

   // create a video mode object
   VideoMode vm(1920,1080);
   // to create and open a window 
   RenderWindow window(vm, "Timber",Style::Fullscreen);

   // create an object that will hold a graphics on gpu
   Texture textureBackground; 
   
   // load graphics in the texture
   textureBackground.loadFromFile("../graphics/background.png");
   
   //Create a sprite
   Sprite spriteBackground;
   
   // attach texture to sprite
   spriteBackground.setTexture(textureBackground);
   
   //set the spritebackground position to cover the screen
   spriteBackground.setPosition(0,0);
   
   
   // make a tree sprite
   Texture textureTree;
   textureTree.loadFromFile("../graphics/tree.png");
   Sprite spriteTree;
   spriteTree.setTexture(textureTree);
   spriteTree.setPosition(810,0);
   
   
   // adding bee in the spritesheet
   Texture textureBee;
   textureBee.loadFromFile("../graphics/bee.png");
   Sprite spriteBee;
    spriteBee.setTexture(textureBee);
   spriteBee.setPosition(0,800);
   
   // is the bee currently moving
   bool beeActive = false;
   
   // how fast the bee can fly
   float beeSpeed= 0.0f;
   
   //make 3 cloud sprites in 1 texture
   Texture textureCloud;
   
   // load 1 new texture
   textureCloud.loadFromFile("../graphics/cloud.png");
   
   // 3 new sprites with the same texture
   Sprite spriteCloud1;
   Sprite spriteCloud2;
   Sprite spriteCloud3;
   spriteCloud1.setTexture(textureCloud);
   spriteCloud2.setTexture(textureCloud);
   spriteCloud3.setTexture(textureCloud);
   
   // position of cloud at left side of screen at different position
   spriteCloud1.setPosition(0,0);
   spriteCloud2.setPosition(0,250);
   spriteCloud3.setPosition(0,500);
   
   //are the clouds currently moving
   bool cloud1Active= false;
   bool cloud2Active = false;
   bool cloud3Active = false;
   
   // how fast the cloud should be moving
   float cloud1Speed = 0.0f;
   float cloud2Speed = 0.0f;
   float cloud3Speed = 0.0f;
   
   
   
   
   
   while(window.isOpen()){
   
   
   /* 
   *****************************
     Handle the player input
     *****************************   
   */
   
   if(Keyboard::isKeyPressed(Keyboard::Escape)){
   
         window.close();
   }
   
   /*
   *******************************
       Update the scene
   ********************************
   */
   
    
   // managing the cloud 
   //cloud 1
   //if(!cloudActive){
   
       // how fast is the cloud 
   
   //
   
    // clear everything from the last frame
    window.clear();
  

  /*
  ****************************************
 Draw the scene 
 *************************************
  */  
   window.draw(spriteBackground);
   
   //draw the cloud 
   window.draw(spriteCloud1);
   window.draw(spriteCloud2);
   window.draw(spriteCloud3);
   
   //draw the tree
   window.draw(spriteTree);
   
   // draw the insect
   window.draw(spriteBee);

  
  // show everything we just draw
    window.display();
   
   
   }
   
return 0;
}

/*
	g++ timber.cpp -o timber -lsfml-window -lsfml-system -lsfml-graphics
	./timber
	
*/
