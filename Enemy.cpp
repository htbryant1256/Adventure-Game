#include "Enemy.h"
 
Enemy::Enemy(int x, int y)
{
	posX = x;
	posY = y;
	delay = 10;
	seekingDistance = 10;
	entity.setFillColor(sf::Color(150, 100, 100));
	srand(time(NULL));
	health = 5;
}

void Enemy::update(OverWorldMap& overWorldMap, int playerPosX, int playerPosY)
{
	if (updateDelay <= 0) {
		if (CommonMathFunctions::distanceFormula(playerPosX, posX, playerPosY, posY) <= seekingDistance) {
			seekPlayer(overWorldMap, playerPosX, playerPosY);
		}
		else {
			randomlyWalk(overWorldMap);
		}
	}
	updateDelay--;
	if (hit) {
		entity.setFillColor(sf::Color(250, 250, 250));
	}
	else {
		entity.setFillColor(sf::Color(150, 100, 100));
	}
}

void Enemy::seekPlayer(OverWorldMap& overWorldMap, int playerPosX, int playerPosY)
{
	if (playerPosX > posX && overWorldMap.tileMap[posY][posX + 1] == 'g' && posX + 1 != playerPosX) {
		posX += 1;
		entityDirection.setRotation(-90);
	}
	else if (playerPosX < posX && overWorldMap.tileMap[posY][posX - 1] == 'g' && posX +- 1 != playerPosX) {
		posX -= 1;
		entityDirection.setRotation(90);
	}
	if (playerPosY > posY && overWorldMap.tileMap[posY + 1][posX] == 'g' && posY + 1 != playerPosY) {
		posY += 1;
		entityDirection.setRotation(0);
	}
	else if (playerPosY < posY && overWorldMap.tileMap[posY - 1][posX] == 'g' && posY - 1 != playerPosY) {
		posY -= 1;
		entityDirection.setRotation(180);
	}
	updateDelay = delay;
}

void Enemy::randomlyWalk(OverWorldMap& overWorldMap)
{
	int movement = rand() % 4 + 1;

	if (movement == 1 && overWorldMap.tileMap[posY][posX + 1] == 'g') {
		posX += 1;
		entityDirection.setRotation(-90);
	}
	if (movement == 2 && overWorldMap.tileMap[posY][posX - 1] == 'g') {
		posX -= 1;
		entityDirection.setRotation(90);
	}
	if (movement == 3 && overWorldMap.tileMap[posY + 1][posX] == 'g') {
		posY += 1;
		entityDirection.setRotation(0);
	}
	if (movement == 4 && overWorldMap.tileMap[posY - 1][posX] == 'g') {
		posY -= 1;
		entityDirection.setRotation(180);
	}
	updateDelay = delay;
}
