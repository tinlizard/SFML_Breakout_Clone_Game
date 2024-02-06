#include "Ball.h"
#include "Bricks.h"
#include "Paddle.h"
#include "Bricks.h"

using RectangleShapeVector = std::vector<sf::RectangleShape>;

void initText(sf::Text& text, sf::Font& font, int x, int y);

int main()
{
    // create the window
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    int score = 0;
    int lives = 3;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Breakout");

    sf::RectangleShape paddle = drawPaddle();
    sf::CircleShape ball(10);
    Ball ballShape(200, 250, 10.f, sf::Color(100, 250, 50),0.05f,0.05f,ball);
    ballShape.ball.setPosition(sf::Vector2f(ballShape.x, ballShape.y));
    ballShape.ball.setFillColor(ballShape.color); 

    sf::Font font;
    sf::Text scoreText;
    sf::Text livesText;
    if (!font.loadFromFile("C:\\Users\\willb\\OneDrive\\Documents\\arial-font\\arial.ttf")) {
        std::cout << "Error loading font! \n";
    }
   initText(scoreText,font,5,20);
   initText(livesText,font,700,20);

    std::vector<Brick> bricks = { 
        Brick(5, 50, 70, 20, sf::Color(100, 250, 50)), 
        Brick(5, 90, 70, 20, sf::Color(100, 250, 50)),  
        Brick(5, 130, 70, 20, sf::Color(100, 250, 50)),
        Brick(5, 170, 70, 20, sf::Color(100, 250, 50))
    };

    //take a vector of RectangleShapes and create another vector out of that so that each bricksArr is kept inside one array
    std::vector<RectangleShapeVector> bricksArrays = {}; 
    std::vector<sf::RectangleShape>eachBrick = {};
    for (auto& brick : bricks) {
        bricksArrays.push_back(createBricks(brick));
    }
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        ballShape.ball.move(ballShape.ballOffsetX,ballShape.ballOffsetY);
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
        //draw each brick in each bricks array
        for (auto& item : bricksArrays) {
            for (int i = 0; i<10; i++) {
                window.draw(item[i]);
            }
        }
        
        window.draw(ballShape.ball);
        ballShape.checkCollisionWithPaddle(paddle);
        ballShape.checkCollisionWithBricks(bricksArrays,score);
        ballShape.checkBallOffScreen(bricksArrays,score,lives); 
        ballShape.checkWallCollision();
        ballShape.reverseOnWallHit();
        scoreText.setString(std::to_string(score));
        livesText.setString(std::to_string(lives)); 
        window.draw(scoreText);
        window.draw(livesText);
        // end the current frame
        window.display();
    }

    return 0;
}

void initText(sf::Text& text, sf::Font& font, int x, int y) {
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(x, y));
}
