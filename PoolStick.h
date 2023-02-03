//
// Created by Trevor Buchanan, Zack Davis, Mahdi Alhabbarah, Mikaela Smith on 12/1/22.
//

#ifndef SFML_SILICON_POOLSTICK_H
#define SFML_SILICON_POOLSTICK_H

#include <SFML/Graphics.hpp>

class PoolStick : public sf::RectangleShape {
public:

    PoolStick();
    PoolStick(const sf::Color &stickColor, const sf::Vector2f &newSize, const sf::Vector2f &newPos, float angle);
    ~PoolStick();
private:
};


#endif //SFML_SILICON_POOLSTICK_H
