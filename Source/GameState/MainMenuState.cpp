//
// Created by baptiste on 16/07/17.
//

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

#include "MainMenuState.h"
#include "../AppEngine.h"
#include "PlayingState.h"

MainMenuState* MainMenuState::m_instance = nullptr;

MainMenuState* MainMenuState::Instance() {
    if(!m_instance) {
        m_instance = new MainMenuState();
    }
    return m_instance;
}

void MainMenuState::init(AppEngine* engine) {
    app = engine;
    if(!font.loadFromFile("./../Ressources/Fonts/Lato-Regular.ttf")) {
        exit(0);
    }
}

void MainMenuState::clean() {
    app = nullptr;
}

void MainMenuState::handleEvents(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            int y = event.mouseButton.y;

            if(event.mouseButton.x > 100 && event.mouseButton.x < 350) {
                if(y > 200 && y < 245) {
                    app->pushState(PlayingState::Instance());
                }
                else if(y > 260 && y < 305) {
                    app->getWindow()->close();
                }
                else if(y > 320 && y < 365) {
                    app->getWindow()->close();
                }
            }
        }
    }
}

void MainMenuState::update() {

}

void MainMenuState::draw() {
    sf::RectangleShape rect;
    sf::Text text;

    rect.setFillColor(sf::Color::Red);
    rect.setSize(sf::Vector2f(250, 45));

    text.setFont(font);
    text.setFillColor(sf::Color::Yellow);

    std::string title[3] = {"Lancer un partie", "Options", "Quitter"};
    for (int i = 0; i < 3; ++i) {
        rect.setPosition(100, 200 + 60*i);
        app->getWindow()->draw(rect);

        text.setString(title[i]);
        text.setPosition(115, 205 + 60*i);
        app->getWindow()->draw(text);
    }

    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);


    text.setString("Pseudo");
    text.setPosition(600, 205 - 25);
    app->getWindow()->draw(text);

    text.setString("Scores");
    text.setPosition(750, 205 - 25);
    app->getWindow()->draw(text);

    text.setString("Nbr de lignes");
    text.setPosition(900, 205 - 25);

    app->getWindow()->draw(text);

    std::vector<Score> list = ScoreManager::Instance()->getScore();
    int i = 0;
    for (std::vector<Score>::iterator it=list.begin(); it!=list.end(); ++it) {
        text.setString(it->getName());
        text.setPosition(600, 205 + 25*i);
        app->getWindow()->draw(text);

        text.setString(sf::String(std::to_string(it->getScore())));
        text.setPosition(750, 205 + 25*i);
        app->getWindow()->draw(text);

        text.setString(sf::String(std::to_string(it->getLine())));
        text.setPosition(900, 205 + 25*i);
        app->getWindow()->draw(text);
        i++;
    }
}