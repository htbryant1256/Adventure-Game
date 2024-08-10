#include "EnemyManager.h"

void EnemyManager::update(OverWorldMap& overWorldMap, int playerPosX, int playerPosY)
{
	int index = -1;
	int counter = 0;
	populateMap(overWorldMap, playerPosX, playerPosY);
	for (auto& element : enemyVector) {
		element.update(overWorldMap, playerPosX, playerPosY);

		if (element.hit) {
			element.health--;
			element.hit = false;

		}
		if (element.health <= 0) {
			index = counter;
		}
		counter++;
	}
	if (index != -1) {
		enemyVector.erase(enemyVector.begin() + index);
	}
}

void EnemyManager::render(sf::RenderWindow* window, OverWorldMap* overWorldMap)
{
	for (auto& element : enemyVector) {
		element.render(window, overWorldMap);
	}
}

void EnemyManager::populateMap(OverWorldMap& overWorldMap, int playerPosX, int playerPosY)
{
	if (overWorldMap.newMapLoaded == true) {
		enemyVector.clear();
		int numberOfEnemies = rand() % 3 + 1;
		for (int i = 0; i < numberOfEnemies; i++) {
			y = rand() % 14 + 1;
			x = rand() % 28 + 1;

			while (overWorldMap.tileMap[y][x] != 1 || CommonMathFunctions::distanceFormula(playerPosX,x, playerPosY,y) < 10) {
				y = rand() % 14 + 1;
				x = rand() % 28 + 1;
			}
			Enemy enemy(x, y);
			enemyVector.push_back(enemy);
		}
	
		overWorldMap.newMapLoaded = false;
	}
}

EnemyManager::EnemyManager()
{
	srand(time(NULL));
	x = 0;
	y = 0;
	
}
