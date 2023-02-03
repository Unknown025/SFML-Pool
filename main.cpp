// Made by: Trevor Buchanan, Zack Davis, Mahdi Alhabbarah, Mikaela Smith

// Reason for excluding polymorphism in the design of this program is that no convenient use could be found because no functions were used.

#include "Table.h"
#include "Ball.h"
#include "PoolStick.h"
#include "Border.h"
#include "Pockets.h"
#include "cmath"
#include <vector>

#define PI 3.14159265358979323846  /* pi */

void drawHitboxes(sf::RenderWindow &window, sf::FloatRect bounds) {
    sf::VertexArray lines(sf::LinesStrip, 5);
    lines[0].position = sf::Vector2f(bounds.left, bounds.top);
    lines[1].position = sf::Vector2f(bounds.left, bounds.top + bounds.height);
    lines[2].position = sf::Vector2f(bounds.left + bounds.width, bounds.top + bounds.height);
    lines[3].position = sf::Vector2f(bounds.left + bounds.width, bounds.top);
    lines[4].position = sf::Vector2f(bounds.left, bounds.top);

    window.draw(lines);
}

int main() {
    float Magnitude = 100;
    float Scale = 1;
    float StickAngle = 0;
    bool renderCollisionBoxes = true;

    std::vector<Ball *> balls;

    // Create Game Window
    sf::RenderWindow window(sf::VideoMode(800, 900), "Pool Game");
    window.setFramerateLimit(60);

    // Load game
    sf::Font font;
    sf::Text text;

    if (!font.loadFromFile("roboto.ttf")) return -1;
    text.setCharacterSize(24);
    text.setFont(font);
    text.setString("Loading game...");

    // Pool Table Color
    Table Table(sf::Color(50, 150, 25, 255), sf::Vector2f(700, 800), sf::Vector2f(50, 50));

    // Set Border Color
    Border border(sf::Color(150, 75, 0, 150), sf::Vector2f(800, 900), sf::Vector2f(0, 0));

    // North Border
    sf::RectangleShape north(sf::Vector2f(800, 50));

    // East Border
    sf::RectangleShape east(sf::Vector2f(50, 900));
    east.setPosition(750, 0);

    // South Border
    sf::RectangleShape south(sf::Vector2f(800, 50));
    south.setPosition(0, 850);

    // West Border
    sf::RectangleShape west(sf::Vector2f(50, 900));

    //Set Pocket Color
    Pockets Pocket_1(sf::Color::Black, sf::Vector2f(67, 50), sf::Vector2f(35, 0), 45);
    Pockets Pocket_2(sf::Color::Black, sf::Vector2f(50, 67), sf::Vector2f(765, 0), 45);
    Pockets Pocket_3(sf::Color::Black, sf::Vector2f(50, 50), sf::Vector2f(0, 400), 0);
    Pockets Pocket_4(sf::Color::Black, sf::Vector2f(50, 50), sf::Vector2f(750, 400), 0);
    Pockets Pocket_5(sf::Color::Black, sf::Vector2f(50, 67), sf::Vector2f(50, 815), 45);
    Pockets Pocket_6(sf::Color::Black, sf::Vector2f(67, 50), sf::Vector2f(750, 815), 45);

    // Solid Balls
    Ball Solid_1(sf::Color::Red, 14, sf::Vector2f(415, 250));
    Ball Solid_2(sf::Color::Red, 14, sf::Vector2f(400, 275));
    Ball Solid_3(sf::Color::Red, 14, sf::Vector2f(385, 250));
    Ball Solid_4(sf::Color::Red, 14, sf::Vector2f(400, 173));
    Ball Solid_5(sf::Color::Red, 14, sf::Vector2f(340, 173));
    Ball Solid_6(sf::Color::Red, 14, sf::Vector2f(415, 199));
    Ball Solid_7(sf::Color::Red, 14, sf::Vector2f(445, 199));

    // Stripes Balls
    Ball Stripes_1(sf::Color::Blue, 14, sf::Vector2f(370, 225));
    Ball Stripes_2(sf::Color::Blue, 14, sf::Vector2f(430, 225));
    Ball Stripes_3(sf::Color::Blue, 14, sf::Vector2f(385, 199));
    Ball Stripes_4(sf::Color::Blue, 14, sf::Vector2f(355, 199));
    Ball Stripes_5(sf::Color::Blue, 14, sf::Vector2f(430, 173));
    Ball Stripes_6(sf::Color::Blue, 14, sf::Vector2f(460, 173));
    Ball Stripes_7(sf::Color::Blue, 14, sf::Vector2f(370, 173));

    // White Ball & Black Ball
    Ball WhiteBall(sf::Color::White, 14, sf::Vector2f(400, 700));
    Ball BlackBall(sf::Color::Black, 14, sf::Vector2f(400, 225));

    balls.push_back(&WhiteBall);
    balls.push_back(&BlackBall);

//    balls.push_back(&Solid_1);
//    balls.push_back(&Solid_2);
//    balls.push_back(&Solid_3);
//    balls.push_back(&Solid_4);
//    balls.push_back(&Solid_5);
//    balls.push_back(&Solid_6);
//    balls.push_back(&Solid_7);
//
//    balls.push_back(&Stripes_1);
//    balls.push_back(&Stripes_2);
//    balls.push_back(&Stripes_3);
//    balls.push_back(&Stripes_4);
//    balls.push_back(&Stripes_5);
//    balls.push_back(&Stripes_6);
//    balls.push_back(&Stripes_7);

    // Pool Stick
    PoolStick poolStick(sf::Color(150, 75, 0, 255), sf::Vector2f(4, Magnitude),
                        sf::Vector2f(balls[0]->getPosition().x + balls[0]->getRadius() + 5,
                                     balls[0]->getPosition().y + balls[0]->getRadius()), 180);

    sf::Clock clock;
    // Game Loop
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::F1:
                        renderCollisionBoxes = !renderCollisionBoxes;
                        break;
                    default:
                        break;
                }
            }
        }

        window.clear();

        // Draw Table and Border
        window.draw(border);
        window.draw(Table);

        // Draw Pockets
        window.draw(Pocket_1);
        window.draw(Pocket_2);
        window.draw(Pocket_3);
        window.draw(Pocket_4);
        window.draw(Pocket_5);
        window.draw(Pocket_6);

        window.draw(Pockets::CornerCircles(sf::Color::Black, 25, sf::Vector2f(0, 0)));
        window.draw(Pockets::CornerCircles(sf::Color::Black, 25, sf::Vector2f(750, 0)));
        window.draw(Pockets::CornerCircles(sf::Color::Black, 25, sf::Vector2f(0, 850)));
        window.draw(Pockets::CornerCircles(sf::Color::Black, 25, sf::Vector2f(750, 850)));

        for (int i = 0; i < balls.size(); i++) {
            Ball *ball = balls[i];
            if (renderCollisionBoxes) {
                sf::FloatRect bounds = ball->getGlobalBounds();
                drawHitboxes(window, bounds);
            }
            if (ball->disabled) continue;

            ball->moveBall(clock.getElapsedTime());
//            ball->checkBorderCollisions();

//            if (ball->checkPocketCollisions(i == 0))
            window.draw(*ball);

            for (auto other: balls) {
                if (other == ball) continue;

                ball->checkBallCollisions(other);
            }
        }

        if (renderCollisionBoxes) {
            drawHitboxes(window, north.getGlobalBounds());
            drawHitboxes(window, east.getGlobalBounds());
            drawHitboxes(window, south.getGlobalBounds());
            drawHitboxes(window, west.getGlobalBounds());

            text.setString("Velocity: " + std::to_string(balls[0]->velocity)
                           + "\nDirection x: " + std::to_string(balls[0]->direction.x)
                           + "\nDirection y: " + std::to_string(balls[0]->direction.y));
            window.draw(text);
        }

        if (balls[0]->velocity == 0) {
            poolStick.setScale(1, Scale);
            poolStick.setPosition(sf::Vector2f(balls[0]->getPosition().x + balls[0]->getRadius() - 1,
                                               balls[0]->getPosition().y + balls[0]->getRadius()));

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                StickAngle += 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                StickAngle -= 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                if (Scale < 3)
                    Scale += .05;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (Scale > .05)
                    Scale -= .05;
            }

            poolStick.setRotation(StickAngle);
            window.draw(poolStick);

            // Take Shot
            if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) && window.hasFocus()) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                balls[0]->velocity = 10;
                balls[0]->direction.x = .002 * cos((StickAngle + 270) * PI / 180) * Magnitude * Scale * 180 / PI;
                balls[0]->direction.y = .002 * sin((StickAngle + 270) * PI / 180) * Magnitude * Scale * 180 / PI;
//                balls[0]->xVelocity = .002 * cos((StickAngle + 270) * PI / 180) * Magnitude * Scale * 180 / PI;
//                balls[0]->yVelocity = .002 * sin((StickAngle + 270) * PI / 180) * Magnitude * Scale * 180 / PI;
            }
        }

        window.display();
    }
    return 0;
}