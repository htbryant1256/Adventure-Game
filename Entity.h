#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "OverWorldMap.h"
class Entity
{
public:
	int posY;
	int posX;
	void render(sf::RenderWindow* window, OverWorldMap* overWorldMap);

	sf::RectangleShape entity;
	sf::RectangleShape entityDirection;
	int delay;
	int updateDelay = delay;

	enum Direction {
		NORTH = 1,
		EAST = 2,
		SOUTH = 3,
		WEST = 4,
	};
	Direction direction;
private:


};

