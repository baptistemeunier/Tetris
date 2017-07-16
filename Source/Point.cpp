#ifndef CARDCLIENT_POINT_H
#define CARDCLIENT_POINT_H

#include <SFML/Graphics/Color.hpp>

struct Point {
    int x, y;
};

struct Case {
    bool isEmpty = true;
    sf::Color color = sf::Color::White;
};

#endif //CARDCLIENT_POINT_H
