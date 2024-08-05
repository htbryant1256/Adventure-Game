#pragma once
#include "Enemy.h"
#include <stdlib.h>     
#include <time.h>   
class EnemyManager
{
public:
	void update(OverWorldMap& overWorldMap, Player player);
	void render(sf::RenderWindow* window, OverWorldMap& overWorldMap);
	void populateMap(OverWorldMap& overWorldMap, Player player);
	EnemyManager();
private:
	int x;
	int y;
	float distanceFromPlayer(Player player);
	std::vector<Enemy> enemyVector;

};

