#include "bat.h"
#include "ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main() {
	VideoMode vm(1920, 1080);
	
	// Create and Open window
	RenderWindow window(vm, "Pong", Style::Fullscreen);
	
	int score = 0;
	int lives = 3;
	
	Bat bat(1920/2, 1080 - 20);
	Ball ball(1920/2, 0);

	Font font;
	font.loadFromFile("../fonts/newfont.ttf");

	Text hud;
	hud.setFont(font);
	
	// Make it nice and big
	hud.setCharacterSize(75);
	hud.setPosition(25, 20);
	
	Clock clock;
	while (window.isOpen()) {
	
		// Handle the player input
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event :: Closed) {
				window.close();
			}
		}
		
		// If the player is quitting
		if (Keyboard :: isKeyPressed(Keyboard :: Escape)) {
			window.close();
		}
		
		// Handle the pressing and releasing of the arrow
		if (Keyboard :: isKeyPressed(Keyboard :: Left)) {
			bat.moveLeft();
		} else {
			bat.stopLeft();
		}
		
		if (Keyboard :: isKeyPressed(Keyboard :: Right)) {
			bat.moveRight();
		} else {
			bat.stopRight();
		}
		
		Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);
		
		// Update the HUD text
		std :: stringstream ss;
		ss << "Score: " << score << " Lives: " << lives;
		hud.setString(ss.str());
		
		// Ball hitting the bottom
		if (ball.getPosition().top > window.getSize().y) {
			ball.reboundBottom();
			lives--;
			
			if (lives < 1) {
				score = 0;
				lives = 3;
			}
		}
		
		if (ball.getPosition().top < 0) {
			ball.reboundBatorTop();
			score++;
		}
		
		if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x) { 
			ball.reboundSides();
		}
		
		if (ball.getPosition().intersects(bat.getPosition())) {
			ball.reboundBatorTop();
		}
		
		
		// Display 
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
	}
	
	return 0;
}