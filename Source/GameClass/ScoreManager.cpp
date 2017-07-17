//
// Created by baptiste on 16/07/17.
//

#include "ScoreManager.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>

ScoreManager* ScoreManager::m_instance = nullptr;

ScoreManager* ScoreManager::Instance() {
    if(!m_instance) {
        m_instance = new ScoreManager();
    }
    return m_instance;
}

void ScoreManager::readScoreFile() {
    std::ifstream infile("./../Ressources/Files/scores");
    std::string line;

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
    read = true;
}

std::vector<Score> ScoreManager::getScore() {
    if(!read) {
        readScoreFile();
    }
    return listScores;
}

void ScoreManager::addScoreTmp(int score, int line) {
    if(!read) {
        readScoreFile();
    }
    tmpScore = new Score("Joueur", score, line);
}


void ScoreManager::writeScoreFile() {
    if(tmpScore != nullptr) {
        listScores.push_back(*tmpScore);
        std::sort (listScores.begin(), listScores.end());
        std::reverse(listScores.begin(),listScores.end());
        if(listScores.size() > 10) {
            listScores.pop_back();
        }
        delete tmpScore;
        tmpScore = nullptr;
    }
    std::ofstream myfile;
    myfile.open ("./../Ressources/Files/scores");
    for (std::vector<Score>::iterator it=listScores.begin(); it!=listScores.end(); ++it)
        myfile << it->getName() << ' ' << it->getScore() << ' ' << it->getLine() << '\n';
    myfile.close();
}

void ScoreManager::saveScore(std::string name) {
    if(tmpScore != nullptr) {
        tmpScore->setName(name);
        writeScoreFile();
    }
}
