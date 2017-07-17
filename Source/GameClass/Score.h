//
// Created by baptiste on 17/07/17.
//

#ifndef CARDCLIENT_SCORE_H
#define CARDCLIENT_SCORE_H

#include <string>

class Score {
    private:
        std::string name;
        int score;
        int line;

    public:
        Score(std::string name, int score, int line);
        bool operator<(Score const s) const { return score < s.score; }
        std::string getName();

        std::string setName(std::string name);
        int getScore();
        int getLine();
};



#endif //CARDCLIENT_SCORE_H
