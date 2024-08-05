#include "Enemy.h"
 
Enemy::Enemy(int x, int y)
{
	posX = x;
	posY = y;
	delay = 15;
	entity.setFillColor(sf::Color(150, 100, 100));
	srand(time(NULL));
}

void Enemy::update(OverWorldMap& overWorldMap, Player player)
{
	if (updateDelay <= 0) {
		if (distanceFromPlayer(player) <= seekingDistance) {
			seekPlayer(overWorldMap, player);
		}
		else {
			randomlyWalk(overWorldMap, player);
		}
	}
		updateDelay--;
}

void Enemy::seekPlayer(OverWorldMap& overWorldMap, Player player)
{
	if (player.posX > posX && overWorldMap.tileMap[posY][posX + 1] == 'g') {
		posX += 1;
	}
	else if (player.posX < posX && overWorldMap.tileMap[posY][posX - 1] == 'g') {
		posX -= 1;
	}
	if (player.posY > posY && overWorldMap.tileMap[posY + 1][posX] == 'g') {
		posY += 1;
	}
	else if (player.posY < posY && overWorldMap.tileMap[posY - 1][posX] == 'g') {
		posY -= 1;
	}
	updateDelay = delay;
}

void Enemy::randomlyWalk(OverWorldMap& overWorldMap, Player player)
{
	int movement = rand() % 4 + 1;

	if (movement == 1 && overWorldMap.tileMap[posY][posX + 1] == 'g') {
		posX += 1;
	}
	if (movement == 2 && overWorldMap.tileMap[posY][posX - 1] == 'g') {
		posX -= 1;
	}
	if (movement == 3 && overWorldMap.tileMap[posY + 1][posX] == 'g') {
		posY += 1;
	}
	if (movement == 4 && overWorldMap.tileMap[posY - 1][posX] == 'g') {
		posY -= 1;
	}
	updateDelay = delay;
}

float Enemy::distanceFromPlayer(Player player)
{
	return abs(sqrt(pow((player.posX - posX), 2) + pow((player.posY - posY), 2)));
}
