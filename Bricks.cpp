#include "Bricks.h"

Brick::Brick(float x, float y, int width, int height, sf::Color color) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->color = color;
}


//function for drawing bricks
std::vector<sf::RectangleShape> drawBricks(Brick brickShape) {
	//create array of bricks of type RectangleShape
	std::vector<sf::RectangleShape> bricksArr;
	//create five new bricks and add them to the bricks array
	for (int i = 0; i < 9; i++) {
		sf::RectangleShape newBrick;
		newBrick.setFillColor(brickShape.color);
		newBrick.setPosition(sf::Vector2f(brickShape.x + (i * (brickShape.width+10.f)), brickShape.y));
		newBrick.setSize(sf::Vector2f(brickShape.width, brickShape.height));
		bricksArr.push_back(newBrick);
	}
	
	return bricksArr;
}
