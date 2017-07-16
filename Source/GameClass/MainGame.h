//
// Created by baptiste on 13/07/17.
//

#ifndef CARDCLIENT_MAINGAME_H
#define CARDCLIENT_MAINGAME_H


#include <SFML/System/Clock.hpp>
#include "Playfield.h"

class PlayingState;

class MainGame {
private:
    PlayingState* state;
    int order[7] = {0, 1, 2, 3, 4, 5, 6};
    Tetromino* next = nullptr;
    int orderCurrent = 10;

    Playfield playfield;
    Tetromino* tetromino = nullptr;

    sf::Clock clock;
    float speed;

    int score;
    int level;
    int toNextLevel;
public:
    Tetromino* getTetromino() const;
    Tetromino* getNextTetromino() const;

public:
    void init(PlayingState*);
    void clean();

    Case** getPlayfield();
    void newTetromino();

    void update();

    void addScores(int);
    int getScores();
    int getLevel();
};


#endif //CARDCLIENT_MAINGAME_H
