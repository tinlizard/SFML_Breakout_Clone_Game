#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Ball {
	public:
		Ball(float radius, sf::Color color);
		float radius;
		sf::Color color;
};
sf::CircleShape drawBall();
