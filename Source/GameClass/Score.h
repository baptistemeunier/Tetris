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

        /** Opperateur de comparaison pour le tri **/
        bool operator<(Score const s) const { return score < s.score; }

        /** Getter et setter **/
        std::string setName(std::string name);
        std::string getName();
        int getScore();
        int getLine();
};



#endif //CARDCLIENT_SCORE_H
