//
// Created by baptiste on 16/07/17.
//

#ifndef CARDCLIENT_SCOREMANAGER_H
#define CARDCLIENT_SCOREMANAGER_H

#include <vector>
#include "Score.h"

class ScoreManager {
    private:
        static ScoreManager* m_instance;
        ScoreManager() {};

        std::vector<Score> listScores;
        bool read = false;
        void readScoreFile();
        void writeScoreFile();

        Score* tmpScore = nullptr;
    public:
        static ScoreManager* Instance();
        std::vector<Score> getScore();
        void addScoreTmp(int score, int line);
        void saveScore(std::string name);
};


#endif //CARDCLIENT_SCOREMANAGER_H
