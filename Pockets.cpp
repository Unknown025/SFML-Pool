//
// Created by Trevor Buchanan, Zack Davis, Mahdi Alhabbarah, Mikaela Smith on 12/1/22.
//

#include "Pockets.h"

Pockets::Pockets(const sf::Color &pocketsColor, const sf::Vector2f &newSize, const sf::Vector2f &newPos, const float angle) :
        sf::RectangleShape(newSize){
    this->setFillColor(pocketsColor);
    this->setPosition(newPos);
    this->setRotation(angle);
}

sf::CircleShape Pockets::CornerCircles(const sf::Color &pocketsColor, const float& newRadius, const sf::Vector2f& newCPos){
    sf::CircleShape circle;
    circle.setFillColor(pocketsColor);
    circle.setRadius(newRadius);
    circle.setPosition(newCPos);

    return circle;
}