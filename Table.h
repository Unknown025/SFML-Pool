//
// Created by Trevor Buchanan, Zack Davis, Mahdi Alhabbarah, Mikaela Smith on 12/1/22.
//

#ifndef SFML_SILICON_TABLE_H
#define SFML_SILICON_TABLE_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Table : public sf::RectangleShape {
public:
    Table();
    Table(const sf::Color &tableColor, const sf::Vector2f &newSize, const sf::Vector2f &newPos);
    ~Table();
private:
};


#endif //SFML_SILICON_TABLE_H
