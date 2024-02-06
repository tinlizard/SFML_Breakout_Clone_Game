#include "Ball.h"
//constructor for ball
using RectangleShapeVector = std::vector<sf::RectangleShape>;
Ball::Ball(float x, float y,float radius, sf::Color color,float ballOffsetX, float ballOffsetY, sf::CircleShape ball) {
	this->radius = radius;
	this->color = color;
    this->x = x;
    this->y = y;
    this->ballOffsetX = ballOffsetX;
    this->ballOffsetY = ballOffsetY;
    this->ball = ball;
    this->hasCollidedWithWall = false;
}

//method for drawing ball
sf::CircleShape Ball::drawBall() {
    this->ball.setRadius(this->radius);
    this->ball.setFillColor(this->color);
    this->ball.setPosition(sf::Vector2f(this->x, this->y));
    return ball;
}

//method for reversing direction 
void Ball::reverseDirectionY() {
    this->ballOffsetY = -this->ballOffsetY;
}

//method for checking collision with paddle
void Ball::checkCollisionWithPaddle(const sf::RectangleShape& paddle) {
    float currentX = this->ball.getPosition().x;
    float currentY = this->ball.getPosition().y;
    if (this->ball.getGlobalBounds().intersects(paddle.getGlobalBounds())) {
        this->ball.setPosition(currentX-20,currentY-20);
        this->reverseDirectionY();
    }
}

//method for checking for collision between ball and bricks
void Ball::checkCollisionWithBricks(std::vector<RectangleShapeVector>& bricksArray, int& score) {
        for (auto& brickVec : bricksArray) {
            for (auto& brick : brickVec) {
                if (this->ball.getGlobalBounds().intersects(brick.getGlobalBounds()) && (brick.getFillColor() == sf::Color(100, 250, 50))) {
                    brick.setFillColor(sf::Color::Black);
                    score++; 
                    this->reverseDirectionY(); 
                }
            }
        }
}

//check if the ball is off the screen and reset its position if it is
void Ball::checkBallOffScreen(std::vector<RectangleShapeVector>& bricksArray, int& score, int& lives) {
    float currentY = this->ball.getPosition().y;
    bool isOffscreen = false;
    for (auto& brickVec : bricksArray) {
        for (auto& brick : brickVec) {
            if (currentY < 0 || currentY > 600) {
                if(brick.getFillColor()!=sf::Color(100,250,50))
                    brick.setFillColor(sf::Color(100, 250, 50));
                    
                this->ball.setPosition(sf::Vector2f(this->x, this->y));   
                isOffscreen = true;
                this->ballOffsetX = 0.05f;
            }
        }
    }
    if (isOffscreen) {
        lives--; 
        if (lives == 0) {
            score = 0;
            lives = 3; 
        }
        isOffscreen = false;
    }
}

bool Ball::checkWallCollision() {
    float currentX = this->ball.getPosition().x;
    if (currentX <= 0 || currentX >= 800) {
        this->hasCollidedWithWall = true;
        return this->hasCollidedWithWall; 
    }
}

void Ball::reverseOnWallHit() {
    if (this->hasCollidedWithWall) {
        this->ballOffsetX = -this->ballOffsetX;
        if (this->ballOffsetX < 0) {
            this->ballOffsetX -= 0.02f;
        }
        else if(this->ballOffsetX>0){
            this->ballOffsetX += 0.02f;
        }
        this->hasCollidedWithWall = false;
    }
}
