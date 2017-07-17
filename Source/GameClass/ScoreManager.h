//
// Created by baptiste on 16/07/17.
//

#ifndef CARDCLIENT_SCOREMANAGER_H
#define CARDCLIENT_SCOREMANAGER_H

#include <vector>
#include "Score.h"

class ScoreManager {
    private:
        /** Addresse du signleton **/
        static ScoreManager* m_instance;
        ScoreManager() {};

        std::vector<Score> listScores;
        bool read = false;

        /** Lecture ecriture du fichier score **/
        std::string filename = "./../Ressources/Files/scores";
        void readScoreFile();
        void writeScoreFile();

        Score* tmpScore = nullptr;

    public:
        /** Appel du singleton **/
        static ScoreManager* Instance();
        ~ScoreManager();

        std::vector<Score> getScore();
        void addScoreTmp(int score, int line);
        void saveScore(std::string name);
};


#endif //CARDCLIENT_SCOREMANAGER_H
