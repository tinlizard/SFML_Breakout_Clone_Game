#include "Ball.h"
#include "Bricks.h"
#include "Paddle.h"
#include "Bricks.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Breakout");
    sf::RectangleShape paddle = drawPaddle();
    Ball ballShape(400, 300, 10.f, sf::Color(100, 250, 50),0.05f,0.05f);
    sf::CircleShape ball = drawBall(ballShape);
    Brick brickShape(5, 50, 70, 20, sf::Color(100, 250, 50));
    Brick brickShapeTwo(5, 10, 70, 20, sf::Color(100, 250, 50));
    Brick brickShapeThree(5, 90, 70, 20, sf::Color(100, 250, 50));
    Brick brickShapeFour(5, 130, 70, 20, sf::Color(100, 250, 50));
    std::vector<sf::RectangleShape> firstBricksArr = drawBricks(brickShape);
    std::vector<sf::RectangleShape> secondBricksArr = drawBricks(brickShapeTwo);
    std::vector<sf::RectangleShape> thirdBricksArr = drawBricks(brickShapeThree);
    std::vector<sf::RectangleShape> fourthBricksArr = drawBricks(brickShapeFour);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        ball.move(ballShape.ballOffsetX,ballShape.ballOffsetY);
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    paddle.move(-10, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    paddle.move(10, 0);
                }
            }
        }

        window.clear();
        window.draw(paddle);
        //draw each brick in the bricks array
        for (int i = 0; i < 10; i++) {
            window.draw(firstBricksArr[i]);
            window.draw(secondBricksArr[i]);
            window.draw(thirdBricksArr[i]);
            window.draw(fourthBricksArr[i]);
        }
        window.draw(ball);
        checkCollisionWithPaddle(paddle, ball,ballShape.ballOffsetX,ballShape.ballOffsetY);
        // end the current frame
        window.display();
    }

    return 0;
}
