//
// Created by baptiste on 10/07/17.
//

#include <iostream>
#include "Display.h"

void Display::init(std::string name) {
    this->window = std::make_unique<sf::RenderWindow>(sf::VideoMode(Display::WIDTH, Display::HEIGHT), name);
}

void Display::clean() {
    sf::RenderWindow* w = window.release();
    delete w;
}

bool Display::isOpen() {
    return this->window->isOpen();
}

void Display::displayWindow() {
    this->window->display();
}

void Display::checkWindowEvent(sf::Event e) {
    if(e.type == sf::Event::Closed) {
        this->window->close();
    }
}

void Display::clearWindow() {
    this->window->clear();
}

sf::RenderWindow* Display::getWindow() {
    return this->window.get();
}