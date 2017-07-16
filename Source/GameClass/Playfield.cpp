
#include <iostream>
#include "Playfield.h"
#include "Tetromino.h"
#include "MainGame.h"

void Playfield::init(MainGame* g) {
    game = g;
    playfield = new Case*[22];
    for(int i=0; i < 22;i++){
        playfield[i] = new Case[10];
    }
}

void Playfield::clean() {
    for(int i=0; i < 22;i++){
        delete[] playfield[i];
    }
    delete[] playfield;
}

Case **Playfield::getPlayfield() {
    return playfield;
}

void Playfield::lock(Tetromino* tetromino) {
    Case c;
    c.color = tetromino->getColor();
    for (int i = 0; i < 4; ++i) {
        c.isEmpty = false;
        playfield[tetromino->center.y + tetromino->grid[i].y][tetromino->center.x + tetromino->grid[i].x] = c;
    }
}

bool Playfield::check(Point* grid) {
    for (int i = 0; i < 4; ++i) {
        int y = grid[i].y;
        int x = grid[i].x;
        if(y < 0 || x < 0 || x > 10){
            return true;
        }

        if(!playfield[grid[i].y][grid[i].x].isEmpty){
            return true;
        }
    }
    return false;
}

void Playfield::checkLines() {
    int taken;
    int line = 0;
    for(int i=19; i >= 0;i--){
        taken = 0;
        for(int j=0; j < 10;j++){
            if(!playfield[i][j].isEmpty) {
                taken++;
            }
        }
        if(taken == 10) {
            for(int j=i; j < 21;j++){
                for(int k=0; k < 10;k++){
                    playfield[j][k].isEmpty = playfield[j+1][k].isEmpty;
                    playfield[j][k].color = playfield[j+1][k].color;
                }
            }
            for(int j=0; j < 10;j++){
                playfield[21][j].isEmpty = true;
            }
            line++;
        }
    }
    if(line != 0) {
        game->addScores(line);
    }
}
bool Playfield::checkLose(Tetromino* tetromino) {
    Point tmp[4];
    for(int i = 0; i < 4; i++){
        tmp[i].x = tetromino->center.x + tetromino->grid[i].x;
        tmp[i].y = tetromino->center.y + tetromino->grid[i].y;
    }
    std::cout << check(tmp) << '\n';
    return check(tmp);
}