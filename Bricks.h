#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Brick {
	public:
		Brick(float x, float y, int width, int height,sf::Color color);
		float x, y;
		int width, height;
		sf::Color color;
};
std::vector<sf::RectangleShape> drawBricks(Brick brickShape);
