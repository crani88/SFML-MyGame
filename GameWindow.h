//
// Created by Andreas Hedbäck on 2018-10-30.
//

#ifndef MYFIRSTGAME_GAMEWINDOW_H
#define MYFIRSTGAME_GAMEWINDOW_H


#include <SFML/Graphics/RenderWindow.hpp>

class GameWindow {
public:
    GameWindow();
    ~GameWindow();
    void initialize();
    sf::RenderWindow* getRef();
private:
    sf::RenderWindow* window;
};


#endif //MYFIRSTGAME_GAMEWINDOW_H
