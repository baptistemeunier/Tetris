#include "AppEngine.h"
#include <iostream>
void AppEngine::init(std::string name) {
    display.init(name);
}

void AppEngine::clean() {
    display.clean();
    for(int i=0; i < states.size(); i++){
        states[i]->clean();
    }
}

sf::RenderWindow* AppEngine::getWindow() {
    return display.getWindow();
}

void AppEngine::routine() {
    while(display.isOpen()) {
        display.clearWindow();

        sf::Event event;

        while (display.getWindow()->pollEvent(event)) {
            display.checkWindowEvent(event);
            states.back()->handleEvents(event);
        }

        states.back()->update();

        states.back()->draw();
        display.displayWindow();
    }
}

void AppEngine::changeState(GameState* state) {
    if(states.size() != 0) {
        states.back()->clean();
        states.pop_back();
    }
    states.push_back(state);
    state->init(this);
}

void AppEngine::pushState(GameState* state) {
    states.push_back(state);
    state->init(this);
}

void AppEngine::popState() {
    if(states.size() != 0) {
        states.back()->clean();
        states.pop_back();
    }
}