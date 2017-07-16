#include <string>
#include <iostream>

#include "PlayingState.h"
#include "../AppEngine.h"
#include "../GameClass/Tetromino.h"
#include "../GameClass/MainGame.h"
#include "PauseState.h"
#include "LoseState.h"


PlayingState* PlayingState::m_instance = nullptr;

PlayingState* PlayingState::Instance() {
    if(!m_instance) {
        m_instance = new PlayingState();
    }
    return m_instance;
}

void PlayingState::init(AppEngine* appEngine) {
    if(!font.loadFromFile("./../Ressources/Fonts/Lato-Regular.ttf")) {
        exit(0);
    }
    app = appEngine;
    game = new MainGame();
    game->init(this);
}

void PlayingState::clean() {
    game->clean();
    delete game;
}


void PlayingState::handleEvents(sf::Event event) {
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            app->pushState(PauseState::Instance());
        }
        if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        {
            if(game->getTetromino()->moveDown()) {
                game->newTetromino();
            }
        }
        else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Z)
        {
            bool lock;
            do {
                lock = game->getTetromino()->moveDown();
            } while (!lock);
            game->newTetromino();
        }
        else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Q)
        {
            game->getTetromino()->moveLeft();
        }
        else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
        {
            game->getTetromino()->moveRight();
        }
        if (event.key.code == sf::Keyboard::A)
        {
            game->getTetromino()->rotate(-1);
        }
        if (event.key.code == sf::Keyboard::E)
        {
            game->getTetromino()->rotate(1);
        }
        if (event.key.code == sf::Keyboard::Space)
        {
            game->holdTetromino();
        }
    }
 }

void PlayingState::update() {
    game->update();
}

void PlayingState::draw() {
    /** Draw playfield **/
        /** BackGround **/
    sf::RectangleShape rectangle(sf::Vector2f(340, 680));
    rectangle.setPosition(sf::Vector2f(15, 15));
    app->getWindow()->draw(rectangle);

        /** All case use **/
    sf::RectangleShape caseUse(sf::Vector2f(34, 34));
    Case** pf = game->getPlayfield();
    for(int i=0; i < 20;i++){
        for(int j=0; j < 10;j++){
            if(!pf[i][j].isEmpty) {
                caseUse.setPosition(sf::Vector2f(15+j*34, 15+(19-i)*34));
                caseUse.setFillColor(pf[i][j].color);
                app->getWindow()->draw(caseUse);
            }
        }
    }

    /** Draw next background **/
    rectangle.setSize(sf::Vector2f(170, 150));
    rectangle.setPosition(sf::Vector2f(370, 15));
    app->getWindow()->draw(rectangle);

    /** Draw next text **/
    sf::Text text1("Prochain", font);
    text1.setCharacterSize(30);
    text1.setPosition(385, 20);
    text1.setStyle(sf::Text::Bold);
    text1.setFillColor(sf::Color::Red);
    app->getWindow()->draw(text1);

    /** Draw hold background **/
    rectangle.setSize(sf::Vector2f(170, 150));
    rectangle.setPosition(sf::Vector2f(370, 15 + 150 + 15));
    app->getWindow()->draw(rectangle);

    /** Draw hold text **/
    sf::Text text("Hold", font);
    text.setCharacterSize(30);
    text.setPosition(385, 20 + 150 + 15);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Red);
    app->getWindow()->draw(text);

    /** Draw Info background **/
    rectangle.setSize(sf::Vector2f(170, 75));
    rectangle.setPosition(sf::Vector2f(370, 15 + 300 + 30));
    app->getWindow()->draw(rectangle);

    /** Draw Info text **/
    std::string score = "Score : ";
    score += std::to_string(game->getScores());
    sf::Text text2(score, font);
    text2.setCharacterSize(15);
    text2.setPosition(385, 30 + 300 + 30);
    text2.setStyle(sf::Text::Bold);
    text2.setFillColor(sf::Color::Red);
    app->getWindow()->draw(text2);

    std::string level = "Niveau : ";
    level += std::to_string(game->getLevel());
    sf::Text text3(level, font);
    text3.setCharacterSize(15);
    text3.setPosition(385, 25 + 30 + 300 + 30);
    text3.setStyle(sf::Text::Bold);
    text3.setFillColor(sf::Color::Red);
    app->getWindow()->draw(text3);

    /** Draw ghost tetromino **/
    Point tmp[4];
    if(game->getTetromino()->getGhost(tmp)){
        for(int i=0; i < 4;i++){
            caseUse.setPosition(sf::Vector2f(
                    15+(tmp[i].x)*34,
                    15+(18 - tmp[i].y)*34)
            );
            sf::Color color(200, 200, 200);
            caseUse.setFillColor(color);
            app->getWindow()->draw(caseUse);
        }
    }

    /** Draw tetromino **/
   for(int i=0; i < 4;i++){
       caseUse.setPosition(sf::Vector2f(
                15+(game->getTetromino()->center.x + game->getTetromino()->grid[i].x)*34,
                15+(19 - game->getTetromino()->center.y - game->getTetromino()->grid[i].y)*34)
       );
       caseUse.setFillColor(game->getTetromino()->getColor());
       app->getWindow()->draw(caseUse);
   }

    /** Draw next tetromino **/
    for(int i=0; i < 4;i++){
        caseUse.setPosition(sf::Vector2f(
                (370+15+34) + (game->getNextTetromino()->grid[i].x)*34,
                (15+15+50+34) + (-game->getNextTetromino()->grid[i].y)*34)
        );
        caseUse.setFillColor(game->getNextTetromino()->getColor());
        app->getWindow()->draw(caseUse);
    }

    /** Draw Hold tetromino **/
    if(game->getHoldTetromino() != nullptr) {
        for(int i=0; i < 4;i++){
            caseUse.setPosition(sf::Vector2f(
                    (370+15+34) + (game->getHoldTetromino()->grid[i].x)*34,
                    (15+150+15+15+50+34) + (-game->getHoldTetromino()->grid[i].y)*34)
            );
            caseUse.setFillColor(game->getHoldTetromino()->getColor());
            app->getWindow()->draw(caseUse);
        }

    }
}

void PlayingState::stopGame() {
    app->pushState(LoseState::Instance());
}
