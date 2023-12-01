#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Ball {
	public:
		Ball(float x, float y, float radius, sf::Color color, float ballOffsetX, float ballOffsetY);
		float x,y,radius,ballOffsetX,ballOffsetY;
		sf::Color color;
};
sf::CircleShape drawBall(const Ball& ballShape);
void reverseDirection(float& ballOffsetX, float& ballOffsetY);
void checkCollisionWithPaddle(sf::RectangleShape& paddle, sf::CircleShape& ball, float& ballOffsetX, float& ballOffsetY);
