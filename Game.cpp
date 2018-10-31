//
// Created by Andreas Hedbäck on 2018-10-10.
//

#include <iostream>
#include <Vector>
#include "Game.h"
#include <algorithm>

Game::Game() {
}

Game::~Game() {
}

void Game::run() {
    gameWindow.initialize();
    window = gameWindow.getRef();

    double previous = getCurrentTime();
    double lag = 0.0;
    while (window->isOpen() && gameOpen) {
        double current = getCurrentTime();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;

        ProcessInput();
        //EventLoop();

        while (lag >= MS_PER_UPDATE) {
            Update();
            lag -= MS_PER_UPDATE;
        }
        Render(lag / MS_PER_UPDATE);

    }
}

void Game::ProcessInput(){
    // Break out to own class later
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        std::vector<sf::Event> currentEvents{};
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window->close();
                gameOpen = false;
                break;
            }
            if (event.type == sf::Event::MouseButtonPressed &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                currentEvents.push_back(event);
                std::cout << "Mouse 1 pressed!" << std::endl;
            }
            if (event.type == sf::Event::KeyPressed)
            {
                currentEvents.push_back(event);
                std::cout << static_cast<char>('a' + event.key.code) << std::endl;
            }

        }
        HandleUserEvents(currentEvents);

}

void Game::HandleUserEvents(std::vector<sf::Event> currentEvents)
{
    // Fix keys held == downpress witout uppress, time/delay?
    if(currentEvents.size() > 0)
    std::cout << currentEvents.size() << std::endl;
    /* ???
    switch (event->user.code) {
        case SDL_:
            GameLoop();
            break;

        default:
            break;
    }
     */
}

void Game::Update() {
    // Update all that has the update function/ own class..
}

void Game::Render(double deltaTime) {
    // Loop through drawables etc.

    // clear the window with black color
    window->clear(sf::Color::Black);

    // draw everything here...
    // window.draw(...);

    // end the current frame
    window->display();
}

double Game::getCurrentTime() {
    auto time = std::chrono::system_clock::now();
    return time.time_since_epoch().count();
}

void Game::EventLoop(std::vector<sf::Event*> currentEvents) {

}
