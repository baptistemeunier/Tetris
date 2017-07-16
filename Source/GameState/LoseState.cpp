//
// Created by baptiste on 14/07/17.
//

#include "LoseState.h"

LoseState* LoseState::m_instance = nullptr;

LoseState *LoseState::Instance() {
    if(!m_instance) {
        m_instance = new LoseState();
    }
    return m_instance;
}

void LoseState::init(AppEngine* appEngine) {
    app = appEngine;
}

void LoseState::clean() {
    app = nullptr;
}

void LoseState::handleEvents(sf::Event) {

}

void LoseState::update() {

}

void LoseState::draw() {

}
