//
// Created by baptiste on 14/07/17.
//

#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include "LoseState.h"
#include "../AppEngine.h"
#include "../GameClass/ScoreManager.h"

LoseState* LoseState::m_instance = nullptr;

LoseState *LoseState::Instance() {
    if(!m_instance) {
        m_instance = new LoseState();
    }
    return m_instance;
}

void LoseState::init(AppEngine* appEngine) {
    app = appEngine;
    if(!font.loadFromFile("./../Ressources/Fonts/Lato-Regular.ttf")) {
        exit(0);
    }
    needName = true;
}

void LoseState::clean() {
    name = "";
    app = nullptr;
}

void LoseState::handleEvents(sf::Event event) {
    if(needName) {
        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::BackSpace) {
                if(name.size() != 0){
                    name.pop_back();
                    std::cout << "coucou" << std::endl;
                }
            } else if(event.key.code == sf::Keyboard::Return) {
                needName = false;
                ScoreManager::Instance()->saveScore(name);
                app->popState();
            }
        }else if (event.type == sf::Event::TextEntered) {
            if((event.text.unicode > 47 && event.text.unicode < 58) || (event.text.unicode > 64 && event.text.unicode < 91) || (event.text.unicode > 96 && event.text.unicode < 123)) {
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                name += static_cast<char>(event.text.unicode);
                std::cout << '|' << name << "|\n";
            }
            std::cout << "ASCII character typed: " << event.text.unicode << std::endl;
        }
    }
}

void LoseState::update() {

}

void LoseState::draw() {
    sf::Text text2(name, font);
    text2.setCharacterSize(15);
    text2.setPosition(385, 30 + 300 + 30);
    text2.setStyle(sf::Text::Bold);
    text2.setFillColor(sf::Color::Red);
    app->getWindow()->draw(text2);
}
