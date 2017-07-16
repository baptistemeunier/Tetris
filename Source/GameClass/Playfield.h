//
// Created by baptiste on 11/07/17.
//

#ifndef CARDCLIENT_PLAYFIELD_H
#define CARDCLIENT_PLAYFIELD_H

#include <SFML/Graphics/Color.hpp>
#include "../Point.cpp"

class Tetromino;
class MainGame;

class Playfield {
    private:
        Case** playfield;
        MainGame* game;

    public:
        void init(MainGame*);
        void clean();
        Case** getPlayfield();
        void lock(Tetromino* tetromino);
        bool check(Point[4]);
        void checkLines();
        bool checkLose(Tetromino*);
};


#endif //CARDCLIENT_PLAYFIELD_H
