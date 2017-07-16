#ifndef CARDCLIENT_DISPLAY_H
#define CARDCLIENT_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class Display {
    private:
        std::unique_ptr<sf::RenderWindow> window = nullptr;

    public:
        static constexpr unsigned int HEIGHT = 720;
        static constexpr unsigned int WIDTH  = 1280;

        void init(std::string name);
        void clean();

        bool isOpen();
        sf::RenderWindow* getWindow();
        void displayWindow();
        void checkWindowEvent(sf::Event);
        void clearWindow();
};


#endif //CARDCLIENT_DISPLAY_H
