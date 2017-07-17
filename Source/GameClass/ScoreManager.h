//
// Created by baptiste on 16/07/17.
//

#ifndef CARDCLIENT_SCOREMANAGER_H
#define CARDCLIENT_SCOREMANAGER_H

#include <vector>
#include "Score.h"

class ScoreManager {
    private:
        std::vector<Score> listScores;
        bool read;
        void readScoreFile();
    public:
        std::vector<Score> getScore();
};


#endif //CARDCLIENT_SCOREMANAGER_H
