#include "EnemyManager.h"

void EnemyManager::update(OverWorldMap& overWorldMap, Player player)
{
	populateMap(overWorldMap, player);
	for (auto& element : enemyVector) {
		element.update(overWorldMap, player);
	}
}

void EnemyManager::render(sf::RenderWindow* window, OverWorldMap& overWorldMap)
{
	for (auto& element : enemyVector) {
		element.render(window, overWorldMap);
	}
}

void EnemyManager::populateMap(OverWorldMap& overWorldMap, Player player)
{
	if (overWorldMap.newMapLoaded == true) {
		enemyVector.clear();
		int numberOfEnemies = rand() % 3 + 1;
		for (int i = 0; i < numberOfEnemies; i++) {
			y = rand() % 9 + 1;
			x = rand() % 18 + 1;

			while (overWorldMap.tileMap[y][x] != 'g' || distanceFromPlayer(player) < 6) {
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

float EnemyManager::distanceFromPlayer(Player player)
{
	return abs(sqrt(pow((player.posX - x), 2) + pow((player.posY - y), 2)));
}