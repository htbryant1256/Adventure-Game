#include "Game.h"
#include <iostream>

void Game::initVariables()
{
	window = nullptr;
    windowWidth = 1920;
    windowHeight = 1080;
    overWorldMap.initOverWorldMap();
}

void Game::initWindow()
{
    videoMode.width = windowWidth;
	videoMode.height = windowHeight;
	window = new sf::RenderWindow(videoMode, "Adventure Game", sf::Style::Titlebar | sf::Style::Close );
    window->setFramerateLimit(60);
}

void Game::pollEvents()
{    
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        }
    }
}

void Game::update()
{
    pollEvents();
    player.update(overWorldMap);
    enemy.update(overWorldMap, player);
}

void Game::render()
{
    window->clear(sf::Color::Black);
    overWorldMap.render(window);
    enemy.render(window, overWorldMap);
    player.render(window, overWorldMap);
    window->display();
}

Game::Game()
{
	initVariables();
	initWindow();
}

Game::~Game()
{
	delete window;
}

