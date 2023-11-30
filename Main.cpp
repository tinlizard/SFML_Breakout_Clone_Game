#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Bricks.h"
#include "Paddle.h"
#include "Bricks.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::RectangleShape paddle = drawPaddle();
    sf::CircleShape ball = drawBall();
    std::vector<sf::RectangleShape> bricks = drawBricks();
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        ball.move(1, 1);
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    paddle.move(-6, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    paddle.move(6, 0);
                }
            }
        }

        window.clear();
        window.draw(paddle);
        //draw each brick in the bricks array
        for (int i = 0; i < 5; i++) {
            window.draw(bricks[i]);
        }
        window.draw(ball);

        // end the current frame
        window.display();
    }

    return 0;
}
