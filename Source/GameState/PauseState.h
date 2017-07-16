//
// Created by baptiste on 13/07/17.
//

#ifndef CARDCLIENT_PAUSESTATE_H
#define CARDCLIENT_PAUSESTATE_H


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include "../GameState.h"

class PauseState : public GameState{
public:
    static PauseState* Instance();
    void init(AppEngine*);
    void clean();

    void handleEvents(sf::Event);
    void update();
    void draw();

private:
    static PauseState *m_instance;
    bool wantQuit;
    sf::Font font;
};


#endif //CARDCLIENT_PAUSESTATE_H
