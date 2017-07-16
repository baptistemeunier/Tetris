//
// Created by baptiste on 10/07/17.
//

#ifndef CARDCLIENT_GAMESTATE_H
#define CARDCLIENT_GAMESTATE_H

#include <SFML/Window/Event.hpp>

class AppEngine;

class GameState {
public:
    virtual void init(AppEngine*) = 0;
    virtual void clean() = 0;

    virtual void handleEvents(sf::Event) = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
private:
protected:
    AppEngine* app;
    GameState() {}
};


#endif //CARDCLIENT_GAMESTATE_H
