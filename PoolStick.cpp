//
// Created by Trevor Buchanan, Zack Davis, Mahdi Alhabbarah, Mikaela Smith on 12/1/22.
//

#include "PoolStick.h"

PoolStick::PoolStick() = default;

PoolStick::PoolStick(const sf::Color &stickColor, const sf::Vector2f &newSize, const sf::Vector2f &newPos, float angle) :
        sf::RectangleShape(newSize) {
    this->setFillColor(stickColor);
    this->setPosition(newPos);
    this->setRotation(angle);
}

PoolStick::~PoolStick() = default;