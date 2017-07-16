//
// Created by baptiste on 11/07/17.
//
// (0) [1] 2 3 4 5 6
// 0 1 2 3 4 5 6
#ifndef CARDCLIENT_TETROMINO_H
#define CARDCLIENT_TETROMINO_H

#include <SFML/System.hpp>
#include <SFML/Graphics/Color.hpp>
#include "../Point.cpp"

class Playfield;

class Tetromino {
    private:
        Playfield* playfield;
        sf::Color color;

        int type;
        int rotation = 0;
        bool isMoving = false;

        int test_grid[7][4][4][2] = {
                {
                        { {-1, 1}, {0, 1}, {0, 0}, {1, 0} },
                        { {1, 1}, {0, -1}, {0, 0}, {1, 0} },
                        { {-1, 0}, {0, 0}, {0, -1}, {1, -1} },
                        { {0, 1}, {-1, -1}, {-1, 0}, {0, 0} },
                },
                {
                        { {-1, 0}, {0, 1}, {0, 0}, {1, 1} },
                        { {0, 1}, {1, -1}, {0, 0}, {1, 0} },
                        { {-1, -1}, {0, 0}, {0, -1}, {1, 0} },
                        { {-1, 1}, {0, -1}, {-1, 0}, {0, 0} },
                },
                {
                        { {0, 1}, {-1, 0}, {0, 0}, {1, 0} },
                        { {0, 1}, {0, -1}, {0, 0}, {1, 0} },
                        { {0, -1}, {-1, 0}, {0, 0}, {1, 0} },
                        { {0, 1}, {0, -1}, {0, 0}, {-1, 0} },
                },
                {
                        { {-1, 1}, {-1, 0}, {0, 0}, {1, 0} },
                        { {1, 1}, {0, -1}, {0, 0}, {0, 1} },
                        { {1, -1}, {-1, 0}, {0, 0}, {1, 0} },
                        { {-1, -1}, {0, -1}, {0, 0}, {0, 1} },
                },
                {
                        { {1, 1}, {-1, 0}, {0, 0}, {1, 0} },
                        { {1, -1}, {0, -1}, {0, 0}, {0, 1} },
                        { {-1, -1}, {-1, 0}, {0, 0}, {1, 0} },
                        { {-1, 1}, {0, -1}, {0, 0}, {0, 1} },
                },
                {
                        { {1, 1}, {1, 0}, {0, 0}, {0, 1} },
                        { {1, -1}, {1, 0}, {0, 0}, {0, -1} },
                        { {0, 0}, {0, -1}, {-1, -1}, {-1, 0} },
                        { {-1, 1}, {-1, 0}, {0, 0}, {0, 1} },
                },
                {
                        { {-1, 0}, {0, 0}, {1, 0}, {2, 0} },
                        { {0, 1}, {0, 0}, {0, -1}, {0, -2} },
                        { {-2, 0}, {-1, 0}, {0, 0}, {1, 0} },
                        { {0, 2}, {0, 1}, {0, 0}, {0, -1} },
                },
        };

        sf::Color test_color[7] = {
                sf::Color::Red,
                sf::Color::Green,
                sf::Color::Black,
                sf::Color::Cyan,
                sf::Color::Black,
                sf::Color::Yellow,
                sf::Color::Blue,
        };

    public:
        Point center;
        Point grid[4];
        Tetromino(int, Playfield*);

        bool moveDown();
        void moveLeft();
        void moveRight();

        void rotate(int);

        sf::Color getColor();

};

#endif //CARDCLIENT_TETROMINO_H
