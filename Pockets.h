//
// Created by Trevor Buchanan, Zack Davis, Mahdi Alhabbarah, Mikaela Smith on 12/1/22.
//

#ifndef SFML_SILICON_POCKETS_H
#define SFML_SILICON_POCKETS_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Pockets : public sf::RectangleShape{
public:
    Pockets(const sf::Color &pocketsColor, const sf::Vector2f &newSize, const sf::Vector2f &newPos, float angle);

    static sf::CircleShape CornerCircles(const sf::Color &pocketsColor, const float& newRadius, const sf::Vector2f& newCPos);

private:
};


#endif //SFML_SILICON_POCKETS_H
