//
// Created by Trevor Buchanan, Zack Davis, Mahdi Alhabbarah, Mikaela Smith on 12/1/22.
//

#ifndef SFML_SILICON_BORDER_H
#define SFML_SILICON_BORDER_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Border : public sf::RectangleShape {
public:
    Border();
    Border(const sf::Color &boarderColor, const sf::Vector2f &newSize, const sf::Vector2f &newPos);
    ~Border();
private:
};


#endif //SFML_SILICON_BORDER_H
