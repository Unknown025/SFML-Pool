//
// Created by Trevor Buchanan, Zack Davis, Mahdi Alhabbarah, Mikaela Smith on 12/1/22.
//

#include "Table.h"

Table::Table() = default;

Table::Table(const sf::Color &tableColor, const sf::Vector2f &newSize, const sf::Vector2f &newPos) :
        sf::RectangleShape(newSize) {
    this->setFillColor(tableColor);
    this->setPosition(newPos);
}

Table::~Table() = default;