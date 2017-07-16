//
// Created by baptiste on 11/07/17.
//

#include "Tetromino.h"
#include "Playfield.h"
#include <iostream>

Tetromino::Tetromino(int index, Playfield* pf) {
    playfield = pf;

    type = index;
    Point point;
    point.x = 5;
    point.y = 18;
    center = point;

    for (int i = 0; i < 4; ++i) {
        point.x = test_grid[index][0][i][0];
        point.y = test_grid[index][0][i][1];
        grid[i] = point;
    }
    color = test_color[index];
}

void Tetromino::resetPosition() {
    Point point;
    point.x = 5;
    point.y = 18;
    center = point;
    for (int i = 0; i < 4; ++i) {
        point.x = test_grid[type][0][i][0];
        point.y = test_grid[type][0][i][1];
        rotation = 0;
        grid[i] = point;
    }
}

bool Tetromino::moveDown() {
    if(isMoving)
        return false;
    isMoving = true;
    /** Move tmp **/
    Point tmp[4];
    for(int i = 0; i < 4; i++){
        tmp[i].x = center.x + grid[i].x;
        tmp[i].y = center.y + grid[i].y - 1;
    }
    /** Check if tetromino will stay on playfield or touch a piece **/
    if(playfield->check(tmp)){
        playfield->lock(this);
        playfield->checkLines();
        isMoving = false;
        return true;
    }
    center.y--;
    isMoving = false;
    return false;
}

void Tetromino::moveLeft() {
    if(isMoving)
        return;
    isMoving = true;
    /** Move tmp **/
    Point tmp[4];
    for(int i = 0; i < 4; i++){
        tmp[i].x = center.x + grid[i].x - 1;
        tmp[i].y = center.y + grid[i].y;
    }

    /** Check if tetromino will stay on playfield or touch a piece **/
    if(!playfield->check(tmp)){
        center.x--;
    }
    isMoving = false;
}

void Tetromino::moveRight() {
    if(isMoving)
        return;
    isMoving = true;
    /** Move tmp **/
    Point tmp[4];
    for(int i = 0; i < 4; i++){
        tmp[i].x = center.x + grid[i].x + 1;
        tmp[i].y = center.y + grid[i].y;
    }

    /** Check if tetromino will stay on playfield or touch a piece **/
    if(!playfield->check(tmp)){
        center.x++;
    }
    isMoving = false;
}

sf::Color Tetromino::getColor() {
    return color;
}

void Tetromino::rotate(int sens) {
    isMoving = true;
    int rotationtmp = rotation + sens;
    if(rotationtmp > 3){
        rotationtmp = 0;
    }
    if(rotationtmp < 0){
        rotationtmp = 3;
    }

    /** Move tmp **/
    Point tmp[4];
    for(int i = 0; i < 4; i++){
        tmp[i].x = center.x + test_grid[type][rotationtmp][i][0];
        tmp[i].y = center.y + test_grid[type][rotationtmp][i][1];
    }

    /** Check if tetromino will stay on playfield or touch a piece **/
    if(!playfield->check(tmp)){
        /** Move **/
        rotation = rotationtmp;
        for(int i = 0; i < 4; i++){
            grid[i].x = test_grid[type][rotationtmp][i][0];
            grid[i].y = test_grid[type][rotationtmp][i][1];
        }
    }
    isMoving = false;
 }

int Tetromino::getType() {
    return type;
}
