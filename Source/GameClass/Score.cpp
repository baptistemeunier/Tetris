//
// Created by baptiste on 17/07/17.
//

#include "Score.h"

Score::Score(std::string n, int s, int l) {
    name = n;
    score = s;
    line = l;
}


std::string Score::setName(std::string n) {
    name = n;
    return name;
}

std::string Score::getName() {
    return name;
}

int Score::getScore() {
    return score;
}

int Score::getLine() {
    return line;
}
