//
// Created by Andreas Hedbäck on 2018-10-30.
//

#include "GameWindow.h"

GameWindow::GameWindow() {
    initialize();
}

GameWindow::~GameWindow() {
    delete window;
    window = nullptr;
}

void GameWindow::initialize() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "My window");
}

sf::RenderWindow *GameWindow::getRef() {
    return window;
}
