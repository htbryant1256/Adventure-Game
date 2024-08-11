#include "Game.h"
#include <iostream>

void Game::initVariables()
{
	window = nullptr;
    windowWidth = 1920;
    windowHeight = 1080;
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
    enemyPlayerInteraction.update(enemyManager, player, overWorldMap);
    enemyManager.update(overWorldMap, player.posX, player.posY);
}

void Game::render()
{
    window->clear(sf::Color::Black);
    overWorldMap.render(window);
    enemyManager.render(window, &overWorldMap);
    player.render(window, &overWorldMap);
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
