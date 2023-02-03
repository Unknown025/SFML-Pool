//
// Created by Trevor Buchanan, Zack Davis, Mahdi Alhabbarah, Mikaela Smith on 12/1/22.
//

#include "Ball.h"

Ball::Ball() = default;

Ball::Ball(const sf::Color &ballColor, const float &newRadius, const sf::Vector2f &newPos) :
        sf::CircleShape(newRadius) {
    this->setFillColor(ballColor);
    this->setPosition(newPos);
}

sf::Vector2f normalize(const sf::Vector2f &source) {
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
        return {source.x / length, source.y / length};
    else
        return source;
}

void Ball::moveBall(sf::Time time) {
    if (velocity > 0.5) {
        normalize(direction);
        float xOffset = (velocity * 50) * direction.x;
        float yOffset = (velocity * 50) * direction.y;
        float x = getPosition().x;
        float y = getPosition().y;
        float newX = x + xOffset;
        float newY = y + yOffset;

        if (newX < 50) {
            direction.x *= -1.f;
        }
        if (newY < 50) {
            direction.y *= -1.f;
        }
        if (newX > 722) {
            direction.x *= -1.f;
        }
        if (newY > 818) {
            direction.y *= -1.f;
        }
        xOffset = (velocity * 50) * direction.x;
        yOffset = (velocity * 50) * direction.y;

        this->setPosition(x + xOffset * time.asSeconds(), y + yOffset * time.asSeconds());
        velocity *= 0.99;
    } else {
        velocity = 0;
    }
}

void Ball::checkBorderCollisions() {
}

bool Ball::checkPocketCollisions(bool special) {
//    if (getPosition().x < 56 && getPosition().y < 56) {
//        if (special)
//            setPosition(sf::Vector2f(400, 700));
//        xVelocity = 0;
//        yVelocity = 0;
//    } else if (getPosition().x > 720 && getPosition().y < 56) {
//        if (special)
//            setPosition(sf::Vector2f(400, 700));
//        xVelocity = 0;
//        yVelocity = 0;
//    } else if (getPosition().x < 56 && getPosition().y > 816) {
//        if (special)
//            setPosition(sf::Vector2f(400, 700));
//        xVelocity = 0;
//        yVelocity = 0;
//    } else if (getPosition().x < 53 && getPosition().y > 386 && getPosition().y < 436) {
//        if (special)
//            setPosition(sf::Vector2f(400, 700));
//        xVelocity = 0;
//        yVelocity = 0;
//    } else if (getPosition().x > 720 && getPosition().y > 386 && getPosition().y < 436) {
//        if (special)
//            setPosition(sf::Vector2f(400, 700));
//        xVelocity = 0;
//        yVelocity = 0;
//    } else if (getPosition().x > 720 && getPosition().y > 816) {
//        if (special)
//            setPosition(sf::Vector2f(400, 700));
//        xVelocity = 0;
//        yVelocity = 0;
//    } else {
//        return true;
//    }
//    if (!special) disabled = true;
//    return false;
    return true;
}

void Ball::checkBallCollisions(Ball *other) {
//    if (other->getGlobalBounds().intersects(this->getGlobalBounds())) {
//        float xVelo = other->xVelocity * other->decelerate;
//        float yVelo = other->yVelocity * other->decelerate;
//
//        float xDif = other->getPosition().x - this->getPosition().x;
//        float yDif = other->getPosition().y - this->getPosition().y;
//
//        float dotProduct = xVelo * xDif + yVelo * yDif;
//        float denominator = pow(1, 2);
//        float projFact = dotProduct / denominator;
//
//
//        xVelocity = projFact * xDif - xVelocity;
//        yVelocity = projFact * yDif - yVelocity;
//
//        other->xVelocity = xVelo - xVelocity - other->xVelocity;
//        other->yVelocity = yVelo - yVelocity - other->yVelocity;
//    }
}

Ball::~Ball() = default;