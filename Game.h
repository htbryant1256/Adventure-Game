#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include <iostream>

#include "OverWorldMap.h"
#include "Player.h"
#include "Enemy.h"
class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	
	OverWorldMap overWorldMap;
	Player player;
	Enemy enemy;
	int windowHeight;
	int windowWidth;

	void initVariables();
	void initWindow();

public:
	Game();
	~Game();
	void pollEvents();
	void update();
	void render();
};

#endif