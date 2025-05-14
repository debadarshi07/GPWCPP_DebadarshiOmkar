#include <SFML/Graphics.hpp>
#include <iostream>
#include"player.cpp"
using namespace sf;

int main(){

// The game will always be in one of four states
	enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };
	
	// start the state with game over
	State state = State::GAME_OVER;
	// get the screen resolution
	Vector2f resolution;
	resolution.x = 1920; // VideoMode :: getDesktopMode().width
    resolution.y = 1080;  // VideoMode :: getDesktopMode().height
	std::cout<<resolution.x<<resolution.y;
	RenderWindow window(VideoMode(resolution.x, resolution.y),
		"Zombie Arena", Style::Fullscreen);
		
   View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));
   window.setView(mainView);
   
   	Clock clock;
   	// How long has the PLAYING state been active
	Time gameTimeTotal;
	// Where is the mouse in relation to world coordinates
	Vector2f mouseWorldPosition;
	// Where is the mouse in relation to screen coordinates
	Vector2i mouseScreenPosition;
		// Create an instance of the Player class
	Player player;
	// The boundaries of the arena
	IntRect arena;
	
	
	while(window.isOpen()){
	    Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				// Pause a game while playing
				if (event.key.code == Keyboard::Return &&
					state == State::PLAYING)
				{
					state = State::PAUSED;
				}

				// Restart while paused
				else if (event.key.code == Keyboard::Return &&
					state == State::PAUSED)
				{
					state = State::PLAYING;
					// Reset the clock so there isn't a frame jump
					clock.restart();
				}
				
				else if (event.key.code == Keyboard::Return &&
					state == State::GAME_OVER)
				{   
				    state = State::LEVELING_UP;
				 }
				 if (state == State::PLAYING)
				{
				
				}
				
		}  
	
	
	
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Handle controls while playing
		if (state == State::PLAYING)
		{
			// Handle the pressing and releasing of the WASD keys
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.moveUp();
			}
			else
			{
				player.stopUp();
			}

			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.moveDown();
			}
			else
			{
				player.stopDown();
			}

			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.moveLeft();
			}
			else
			{
				player.stopLeft();
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.moveRight();
			}
			else
			{
				player.stopRight();
			}
			
			}
			
			 // Handle the levelling up state
		if (state == State::LEVELING_UP)
		{
			// Handle the player levelling up
			if (event.key.code == Keyboard::Num1)
			{
				
				state = State::PLAYING;
				
			}

			if (event.key.code == Keyboard::Num2)
			{
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num3)
			{
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num4)
			{
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num5)
			{
				//healthPickup.upgrade();
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num6)
			{
				//ammoPickup.upgrade();
				state = State::PLAYING;
			}

			if (state == State::PLAYING)
			{
				// Prepare thelevel
				// We will modify the next two lines later
				
				arena.width = 500;
				arena.height = 500;
				arena.left = 0;
				arena.top = 0;
				
				int tileSize = 50;
				player.spawn(arena,resolution, tileSize);
				clock.restart();
        	}
 
     }
     /*
     ******************
      Update the frame
      ******************
      */
      if (state == State::PLAYING)
		{
			// Update the delta time
			Time dt = clock.restart();
			// Update the total game time
			gameTimeTotal += dt;
			// Make a decimal fraction of 1 from the delta time
			float dtAsSeconds = dt.asSeconds();
            // Where is the mouse pointer
			mouseScreenPosition = Mouse::getPosition();

			// Convert mouse position to world coordinates of mainView
			mouseWorldPosition = window.mapPixelToCoords(
				Mouse::getPosition(), mainView);
				
				// Update the player
			player.update(dtAsSeconds, Mouse::getPosition());
			// Make a note of the players new position
			Vector2f playerPosition(player.getCenter());

			// Make the view centre around the player				
		     mainView.setCenter(player.getCenter());
		     }
		     
		     // draw the scene
		     
		if (state == State::PLAYING)
		{
			window.clear();

			// set the mainView to be displayed in the window
			// And draw everything related to it
			window.setView(mainView);
			// Draw the player
			window.draw(player.getSprite());
			
		if (state == State::LEVELING_UP)
		{
		
			
		}

		if (state == State::PAUSED)
		{
	
		}

		if (state == State::GAME_OVER)
		{
	
		}
		

		window.display();
      
      }
     
     } // end of game loop
   	
return 0;
}


