#include "Enemy.h"
#include <stdlib.h>     
#include <time.h>    
Enemy::Enemy()
{
	posX = 10;
	posY = 5;
	delay = 15;
	entity.setFillColor(sf::Color(150, 100, 100));
	srand(time(NULL));
}

void Enemy::update(OverWorldMap& overWorldMap, Player player)
{

	if (updateDelay <= 0) {
		if (abs(sqrt(pow((player.posX - posX), 2) + pow((player.posY - posY), 2))) <= 5) {

			//printf("close: distance = %f\n", abs(sqrt(pow((player.posX - posX), 2) + pow((player.posY - posY), 2))));

			if (player.posX > posX && overWorldMap.tileMap[posY][posX + 1] != 's') {
				posX += 1;
			}
			else if (player.posX < posX && overWorldMap.tileMap[posY][posX - 1] != 's') {
				posX -= 1;
			}
			if (player.posY > posY && overWorldMap.tileMap[posY + 1][posX] != 's') {
				posY += 1;
			}
			else if (player.posY < posY && overWorldMap.tileMap[posY - 1][posX] != 's') {
				posY -= 1;
			}
			updateDelay = delay;
		}
		else {
			int movement = rand() % 4 + 1;

			if (movement == 1 && overWorldMap.tileMap[posY][posX + 1] != 's') {
				posX += 1;
			}
			if (movement == 2 && overWorldMap.tileMap[posY][posX - 1] != 's') {
				posX -= 1;
			}
			if (movement == 3 && overWorldMap.tileMap[posY + 1][posX] != 's') {
				posY += 1;
			}
			if (movement == 4 && overWorldMap.tileMap[posY - 1][posX] != 's') {
				posY -= 1;
			}
			updateDelay = delay;
		}
	}
		updateDelay--;
	
}
