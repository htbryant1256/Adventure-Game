#include "Player.h"

Player::Player()
{
	posX = 1;
	posY = 1;
	delay = 5;
	entity.setFillColor(sf::Color(100,150,100));
}

void Player::updateCollisions(OverWorldMap& overWorldMap)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (overWorldMap.tileMap[posY][posX + 1] != 's' && posY + 1 != 38) {
			/*
			for (auto& element : enemyManager.enemyVector) {
				if (((element.posX == posX) || (element.posX == posX - 1) || (element.posX == posX + 1)) && (element.posY == posY - 1)) {
					printf("HIT NORTH\n");
				}
			}*/
			posX += 1;
			updateDelay = delay;
		}
		direction = EAST;
		entityDirection.setRotation(-90);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (overWorldMap.tileMap[posY][posX - 1] != 's' && posY - 1 != -1) {
			posX -= 1;
			updateDelay = delay;
		}
		direction = WEST;
		entityDirection.setRotation(90);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (overWorldMap.tileMap[posY + 1][posX] != 's' && posY + 1 != 20) {
			posY += 1;
			updateDelay = delay;
		}
		direction = SOUTH;
		entityDirection.setRotation(0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (overWorldMap.tileMap[posY - 1][posX] != 's' && posY - 1 != -1) {
			posY -= 1;
			updateDelay = delay;
		}
		direction = NORTH;
		entityDirection.setRotation(180);
	}
}

void Player::updateScreenChange(OverWorldMap& overWorldMap)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && overWorldMap.tileMap[posY][posX] == 'd' && posX == 37) {
		posX = 0;
		overWorldMap.loadMapRight();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && overWorldMap.tileMap[posY][posX] == 'd' && posX == 0) {
		posX = 37;
		overWorldMap.loadMapLeft();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && overWorldMap.tileMap[posY][posX] == 'd' && posY == 19) {
		posY = 0;
		overWorldMap.loadMapDown();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && overWorldMap.tileMap[posY][posX] == 'd' && posY == 0) {
		posY = 19;
		overWorldMap.loadMapUp();
		updateDelay = delay;
	}
}

void Player::attackEnemy(EnemyManager& enemyManager)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		printf("Attack!\n");
		switch (direction){
			case NORTH:
				for (auto& element : enemyManager.enemyVector) {
					if (((element.posX == posX) || (element.posX == posX - 1) || (element.posX == posX + 1)) && (element.posY == posY - 1)) {
						printf("HIT NORTH\n");
						element.hit = true;
					}
				}
				break;
			case EAST:
				for (auto& element : enemyManager.enemyVector) {
					if (((element.posY == posY) || (element.posY == posY - 1) || (element.posY == posY + 1)) && (element.posX == posX + 1)) {
						printf("HIT EAST \n");
						element.hit = true;
					}
				}
				break;
			case SOUTH:
				for (auto& element : enemyManager.enemyVector) {
					if (((element.posX == posX) || (element.posX == posX - 1) || (element.posX == posX + 1)) && (element.posY == posY + 1)) {
						printf("HIT SOUTH\n");
						element.hit = true;
					}
				}
				break;
			case WEST:
				for (auto& element : enemyManager.enemyVector) {
					if(((element.posY == posY) || (element.posY == posY - 1) || (element.posY == posY + 1)) && (element.posX == posX - 1)) {
						printf("HIT WEST\n");
						element.hit = true;
					}
				}
				break;

		}
		updateDelay = delay;
	}
}

void Player::update(OverWorldMap& overWorldMap, EnemyManager& enemyManager)
{
	if (updateDelay <= 0) {

		//Stone Collisions
		updateCollisions(overWorldMap);
		attackEnemy(enemyManager);
	}
	updateDelay--;
	//Screen Change Logic
	updateScreenChange(overWorldMap);
	
}