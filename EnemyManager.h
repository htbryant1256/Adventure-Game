#pragma once
#include "Enemy.h"
#include <stdlib.h>     
#include <time.h>
#include "CommonMathFunctions.h"
class EnemyManager
{
public:
	void update(OverWorldMap& overWorldMap, int playerPosX, int playerPosY);
	void render(sf::RenderWindow* window, OverWorldMap* overWorldMap);
	void populateMap(OverWorldMap& overWorldMap, int playerPosX, int playerPosY);
	EnemyManager();
	std::vector<Enemy> enemyVector;
private:
	int x;
	int y;
	CommonMathFunctions commonMathFunctions;

};

