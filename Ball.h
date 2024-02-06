#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bricks.h"
#include <vector>

//define ball class properties
class Ball {
	public:
		Ball(float x, float y, float radius, sf::Color color, float ballOffsetX, float ballOffsetY, sf::CircleShape ball);
		float x,y,radius,ballOffsetX,ballOffsetY;
		bool hasCollidedWithWall;
		sf::Color color;
		sf::CircleShape ball;
		sf::CircleShape drawBall();
		void reverseDirectionY();
		void checkCollisionWithPaddle(const sf::RectangleShape& paddle);
		void checkCollisionWithBricks(std::vector<std::vector<sf::RectangleShape>>& bricksArray, int& score);
		void checkBallOffScreen(std::vector<std::vector<sf::RectangleShape>>& bricksArray, int& score, int& lives);
		bool checkWallCollision();
		void reverseOnWallHit();
};
