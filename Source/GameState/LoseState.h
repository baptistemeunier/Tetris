//
// Created by baptiste on 14/07/17.
//

#ifndef CARDCLIENT_LOSESTATE_H
#define CARDCLIENT_LOSESTATE_H

#include <SFML/Window/Event.hpp>
#include "../GameState.h"

class LoseState : public GameState{
    public:
        static LoseState* Instance();
        void init(AppEngine*);
        void clean();

        void handleEvents(sf::Event);
        void update();
        void draw();

    private:
        static LoseState *m_instance;

};


#endif //CARDCLIENT_LOSESTATE_H
