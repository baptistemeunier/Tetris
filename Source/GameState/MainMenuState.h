//
// Created by baptiste on 16/07/17.
//

#ifndef CARDCLIENT_MAINMENUSTATE_H
#define CARDCLIENT_MAINMENUSTATE_H

#include "../GameState.h"
#include "../GameClass/ScoreManager.h"

class MainMenuState : public GameState {
public:

    static MainMenuState* Instance();

    void init(AppEngine *engine) override;
    void clean() override;
    void handleEvents(sf::Event event) override;
    void update() override;
    void draw() override;

private:
    static MainMenuState* m_instance;
    sf::Font font;
};


#endif //CARDCLIENT_MAINMENUSTATE_H
