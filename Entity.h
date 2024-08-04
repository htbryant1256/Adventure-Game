#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "OverWorldMap.h"
class Entity
{
public:
	int posY = 1;
	int posX = 1;
	void render(sf::RenderWindow* window, OverWorldMap overWorldMap);
	void update(OverWorldMap& overWorldMap);
private:

	sf::RectangleShape entity;

	int delay = 5;
	int updateDelay = delay;
};

