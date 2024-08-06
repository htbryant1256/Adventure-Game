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

	int delay;
	int updateDelay = delay;

	enum Direction {
		NORTH = 1,
		EAST = 2,
		SOUTH = 3,
		WEST = 4,
	};
	Direction direction;

	int health;
	bool hit = false;

private:


};

