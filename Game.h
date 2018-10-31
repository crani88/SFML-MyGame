//
// Created by Andreas Hedbäck on 2018-10-10.
//

#ifndef MYFIRSTGAME_GAME_H
#define MYFIRSTGAME_GAME_H


#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include <chrono>

class Game {
public:
    Game();
    ~Game();
    void run();
private:
    void ProcessInput();
    void EventLoop(std::vector<sf::Event*> currentEvents);
    
    void HandleUserEvents(std::vector<sf::Event> currentEvents);
    void Update();
    void Render(double deltaTime);
    double getCurrentTime();
    int MS_PER_UPDATE{16};
    bool gameOpen{true};
    GameWindow gameWindow{};
    sf::RenderWindow* window;
};


#endif //MYFIRSTGAME_GAME_H
