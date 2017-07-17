//
// Created by baptiste on 10/07/17.
//

#ifndef CARDCLIENT_PLAYINGSTATE_H
#define CARDCLIENT_PLAYINGSTATE_H

#include <SFML/Graphics.hpp>
#include "../GameState.h"

class MainGame;

class PlayingState : public GameState {
    public:
        static PlayingState* Instance();
        void init(AppEngine*);
        void clean();

        void handleEvents(sf::Event);
        void update();
        void draw();

        void stopGame();
    private:
        MainGame* game;
        sf::Font font;

        static PlayingState* m_instance;
        PlayingState() {};
};

#endif //CARDCLIENT_PLAYINGSTATE_H
