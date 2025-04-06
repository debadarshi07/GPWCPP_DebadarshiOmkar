#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat {
	private:
		Vector2f m_Position;
		// A rectangle object
		RectangleShape m_Shape;
		
		float m_Speed = 1000.0f;
		
		bool m_MovingRight = false;
		bool m_MovingLeft = false;
	
	public:
		Bat(float startX, float startY);
		FloatRect getPosition();
		ReactangleShape getShape();
		
		void moveLeft();
		void moveRight();
		void stopRight();
		void stopLeft();
		void update(Time dt);
}