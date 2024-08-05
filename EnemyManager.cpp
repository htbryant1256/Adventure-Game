#include "EnemyManager.h"

void EnemyManager::update(OverWorldMap& overWorldMap, int playerPosX, int playerPosY)
{
	populateMap(overWorldMap, playerPosX, playerPosY);
	for (auto& element : enemyVector) {
		element.update(overWorldMap, playerPosX, playerPosY);
	}
}

void EnemyManager::render(sf::RenderWindow* window, OverWorldMap& overWorldMap)
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
			y = rand() % 9 + 1;
			x = rand() % 18 + 1;

			while (overWorldMap.tileMap[y][x] != 'g' || distanceFromPlayer(playerPosX, playerPosY) < 6) {
				y = rand() % 9 + 1;
				x = rand() % 18 + 1;
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

float EnemyManager::distanceFromPlayer(int playerPosX, int playerPosY)
{
	return abs(sqrt(pow((playerPosX - x), 2) + pow((playerPosY - y), 2)));
}