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

ScoreManager::~ScoreManager() {
    delete tmpScore; // Liberation du pointeur

}
void ScoreManager::readScoreFile() {
    std::ifstream infile(filename);
    std::string line;

    /** Lecture du fichier ligne par ligne **/
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string name;
        int score, nbLine;
        if (!(iss >> name >> score >> nbLine)) {
            std::cout << "ERREUR \n";
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
        listScores.push_back(*tmpScore); // Ajout du score
        std::sort (listScores.begin(), listScores.end()); // Tri des scores
        std::reverse(listScores.begin(),listScores.end());
        if(listScores.size() > 20) { // Si dépassement de la limite du nombre de score
            listScores.pop_back(); // Retrait du dernier score
        }
        delete tmpScore; // Liberation du pointeur
        tmpScore = nullptr;
    }
    /** Ecriture du fichier ligne par ligne **/
    std::ofstream myfile;
    myfile.open (filename);
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