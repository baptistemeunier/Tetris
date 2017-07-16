//
// Created by baptiste on 13/07/17.
//

#include "PauseState.h"
#include "../AppEngine.h"
#include <iostream>

PauseState* PauseState::m_instance = nullptr;

PauseState* PauseState::Instance() {
    if(!m_instance) {
        m_instance = new PauseState();
    }
    return m_instance;
}

void PauseState::init(AppEngine* appEngine) {
    wantQuit = false;
    if(!font.loadFromFile("./../Ressources/Fonts/Lato-Regular.ttf")) {
        exit(0);
    }
    app = appEngine;
}

void PauseState::clean() {
    app = nullptr;
}

void PauseState::handleEvents(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            app->popState();
        }
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down) {
            wantQuit = !wantQuit;
        }
        if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space) {
            if(wantQuit) {
                app->getWindow()->close();
            } else {
                app->popState();
            }
        }
    }
}

void PauseState::update() {

}

void PauseState::draw() {

    sf::Text text1("Retour au jeu", font);
    text1.setCharacterSize(30);
    text1.setPosition(510, 250);
    text1.setStyle(sf::Text::Bold);
    text1.setFillColor(sf::Color::Red);

    sf::Text text2("Quitter le jeu", font);
    text2.setCharacterSize(30);
    text2.setPosition(510, 330);
    text2.setStyle(sf::Text::Bold);
    text2.setFillColor(sf::Color::Red);

    sf::RectangleShape rectangleShape(sf::Vector2f(210, 55));
    rectangleShape.setOutlineColor(sf::Color::Yellow);
    rectangleShape.setFillColor(sf::Color::Transparent);
    rectangleShape.setOutlineThickness(3);
    if(wantQuit){
        rectangleShape.setPosition(500, 325);
    } else {
        rectangleShape.setPosition(500, 245);
    }

    app->getWindow()->draw(text1);
    app->getWindow()->draw(text2);
    app->getWindow()->draw(rectangleShape);
}
