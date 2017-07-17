//
// Created by baptiste on 16/07/17.
//

#include "ScoreManager.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

void ScoreManager::readScoreFile() {
    std::ifstream infile("./../Ressources/Files/scores");
    std::string line;

    //chloe:40:1
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string name;
        int score, nbLine;
        if (!(iss >> name >> score >> nbLine)) {
            std::cout << "ERREUR \n";
            exit(1);
        }
        Score s(name, score, nbLine);
        listScores.push_back(s);
    }
    std::sort (listScores.begin(), listScores.end());
    std::reverse(listScores.begin(),listScores.end());
    read = true;
}

std::vector<Score> ScoreManager::getScore() {
    if(!read) {
        readScoreFile();
    }
    return listScores;
}
