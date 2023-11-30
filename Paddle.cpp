#include <iostream>
#include <SFML/Graphics.hpp>

//draw the paddle
sf::RectangleShape drawPaddle() {
    sf::RectangleShape paddle;
    paddle.setFillColor(sf::Color(100, 250, 50));
    paddle.setPosition(sf::Vector2f(320.f, 580.f));
    paddle.setSize(sf::Vector2f(100.f, 30.f));
    return paddle;
}
