//
// Created by Trevor Buchanan, Zack Davis, Mahdi Alhabbarah, Mikaela Smith on 12/1/22.
//

#include "Border.h"

Border::Border() = default;

Border::Border(const sf::Color &BoarderColor, const sf::Vector2f &newSize, const sf::Vector2f &newPos) :
        sf::RectangleShape(newSize) {
    this->setFillColor(BoarderColor);
    this->setPosition(newPos);
}

Border::~Border() = default;