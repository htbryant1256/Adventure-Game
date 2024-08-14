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
		element.render(window);
	}
}

void EnemyManager::populateMap(OverWorldMap& overWorldMap, int playerPosX, int playerPosY)
{
	if (overWorldMap.newMapLoaded == true) {

		if (enemiesGenerated) {
			enemyVector.clear();
			numberOfEnemies = rand() % 3 + 1;
			enemiesGenerated = false;
		}
		if (enemySpawnDelay <= 0) {
			if (numberOfEnemies > 0) {
				y = rand() % 14 + 1;
				x = rand() % 28 + 1;

				while (overWorldMap.tileMap[y][x] > 3 || CommonMathFunctions::distanceFormula(playerPosX, x, playerPosY, y) < 10) {
					y = rand() % 14 + 1;
					x = rand() % 28 + 1;
				}
				Enemy enemy(x, y);
				enemyVector.push_back(enemy);
				numberOfEnemies--;
			}
			enemySpawnDelay = 7;
		}
		enemySpawnDelay--;
	
	}
	if (numberOfEnemies <= 0) {
		overWorldMap.newMapLoaded = false;
		enemiesGenerated = true;
	}
}

EnemyManager::EnemyManager()
{
	srand(time(NULL));
	x = 0;
	y = 0;
	
}
