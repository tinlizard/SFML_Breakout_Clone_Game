#include "Ball.h"

Ball::Ball(float radius, sf::Color color) {
	this->radius = radius;
	this->color = color;
}

//function for drawing ball
sf::CircleShape drawBall() {
    Ball ballShape(10.f, sf::Color(100, 250, 50));
    sf::CircleShape ball(ballShape.radius);
    ball.setFillColor(ballShape.color);
    ball.setPosition(sf::Vector2f(400.f, 300.f));
    return ball;
}
