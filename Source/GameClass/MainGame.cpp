//
// Created by baptiste on 13/07/17.
//

#include "MainGame.h"
#include "Tetromino.h"
#include "../GameState/PlayingState.h"

void MainGame::init(PlayingState* s) {
    if (!music.openFromFile("./../Ressources/Musics/theme.ogg"))
        exit(1);
    music.play();
    music.setVolume(20);
    music.setLoop(true);

    state = s;
    playfield.init(this);
    newTetromino();
    score = 0;
    level = 0;
    toNextLevel = 10;
    clock.restart();
    speed = 1;
}

void MainGame::clean() {
    playfield.clean();
    if(tetromino != nullptr) {
        delete tetromino;
    }
    if(next != nullptr) {
        delete next;
    }
    if(hold != nullptr) {
        delete hold;
    }
}

Case** MainGame::getPlayfield() {
    return playfield.getPlayfield();
}

Tetromino* MainGame::getTetromino() const {
    return tetromino;
}

Tetromino* MainGame::getNextTetromino() const {
    return next;
}

Tetromino* MainGame::getHoldTetromino() const {
    return hold;
}

void MainGame::newTetromino() {
    canHold = true;
    if(tetromino != nullptr) {
        delete tetromino;
    }
    if(next == nullptr) {
        std::srand(std::time(0));
        std::random_shuffle(std::begin(order), std::end(order));
        next = new Tetromino(order[0], &playfield);
        orderCurrent = 0;
    }

    tetromino = next;
    orderCurrent++;
    if(orderCurrent > 6) {
        std::srand(std::time(0));
        std::random_shuffle(std::begin(order), std::end(order));
        orderCurrent = 0;
    }
    next = new Tetromino(order[orderCurrent], &playfield);
    if(playfield.checkLose(tetromino)) {
        state->stopGame();
        music.stop();
    }
}

void MainGame::addScores(int line) {
    score+= (line == 1)?40:((line == 2)?100:((line == 3)?300:1200)) * (level + 1);
    toNextLevel -= line;
    if(toNextLevel <= 0) {
        level++;
        toNextLevel = 10 + toNextLevel;
        speed -= speed/3;
        music.setPitch(1 + level/100);
    }
}

int MainGame::getScores() {
    return score;
}

int MainGame::getLevel() {
    return level;
}

void MainGame::update() {
    if(clock.getElapsedTime().asSeconds() > speed) {
        clock.restart();
        if(getTetromino()->moveDown()) {
            newTetromino();
        }
    }
}

void MainGame::holdTetromino() {
    if(canHold) {
        if(hold == nullptr){
            tetromino->resetPosition();
            hold = tetromino;
            tetromino = nullptr;
            newTetromino();
        } else if (hold->getType() != tetromino->getType()) {
            tetromino->resetPosition();
            Tetromino* tmp = tetromino;
            tetromino = hold;
            hold = tmp;
        }
        canHold = false;
    }
}
