//
// Created by baptiste on 10/07/17.
//

#ifndef CARDCLIENT_APPENGINE_H
#define CARDCLIENT_APPENGINE_H

#include <string>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Display.h"
#include "GameState.h"

class AppEngine {
    private:
        Display display;
        std::vector<GameState*> states;

    public:
        void init(std::string name);
        void clean();

        sf::RenderWindow* getWindow();
        void routine();

        void changeState(GameState* state);
        void pushState(GameState* state);
        void popState();


};


#endif //CARDCLIENT_APPENGINE_H
