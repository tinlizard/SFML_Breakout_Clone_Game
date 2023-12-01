#include "Ball.h"


Ball::Ball(float x, float y,float radius, sf::Color color,float ballOffsetX, float ballOffsetY) {
	this->radius = radius;
	this->color = color;
    this->x = x;
    this->y = y;
    this->ballOffsetX = ballOffsetX;
    this->ballOffsetY = ballOffsetY;
}

//function for drawing ball
sf::CircleShape drawBall(const Ball& ballShape) {
    sf::CircleShape ball(ballShape.radius);
    ball.setFillColor(ballShape.color);
    ball.setPosition(sf::Vector2f(ballShape.x, ballShape.y));
    return ball;
}

void reverseDirection(float& ballOffsetX, float& ballOffsetY) {
    ballOffsetX = -ballOffsetX;
    ballOffsetY = -ballOffsetY;
}

void checkCollisionWithPaddle(sf::RectangleShape& paddle, sf::CircleShape& ball, float& ballOffsetX, float& ballOffsetY) {
    if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds())) {
        int currentX = ball.getPosition().x;
        int currentY = ball.getPosition().y;
        ball.setPosition(currentX-20,currentY-20);
        reverseDirection(ballOffsetX, ballOffsetY);
    }
}
