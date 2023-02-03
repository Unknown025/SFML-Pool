//
// Created by Trevor Buchanan, Zack Davis, Mahdi Alhabbarah, Mikaela Smith on 12/1/22.
//

#ifndef SFML_SILICON_BALL_H
#define SFML_SILICON_BALL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>

class Ball : public sf::CircleShape
{
public:
    sf::Vector2f direction;
    float velocity;
    bool disabled = false;

    Ball();
    Ball(const sf::Color& ballColor, const float& newRadius, const sf::Vector2f& newPos);

    void checkBorderCollisions();

    // Checks pocket collisions. If special is true, resets the ball's position if collided.
    // Returns if the ball should be drawn.
    bool checkPocketCollisions(bool special);

    void checkBallCollisions(Ball* other);

    void moveBall(sf::Time time);

    ~Ball();
private:
};


#endif //SFML_SILICON_BALL_H
