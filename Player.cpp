#include "Player.h"

Player::Player()
{
	posX = 1;
	posY = 1;
	delay = 8;
	entity.setFillColor(sf::Color(100,150,100));
}

void Player::updateCollisions(OverWorldMap& overWorldMap)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (overWorldMap.tileMap[posY][posX + 1] != 's' && posY + 1 != 19) {
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
		if (overWorldMap.tileMap[posY + 1][posX] != 's' && posY + 1 != 10) {
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && overWorldMap.tileMap[posY][posX] == 'd' && posX == 18) {
		posX = 0;
		overWorldMap.loadMapRight();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && overWorldMap.tileMap[posY][posX] == 'd' && posX == 0) {
		posX = 18;
		overWorldMap.loadMapLeft();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && overWorldMap.tileMap[posY][posX] == 'd' && posY == 9) {
		posY = 0;
		overWorldMap.loadMapDown();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && overWorldMap.tileMap[posY][posX] == 'd' && posY == 0) {
		posY = 9;
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
						printf("HIT\n");
					}
				}
				break;

		}
	}
}

void Player::update(OverWorldMap& overWorldMap, EnemyManager& enemyManager)
{
	if (updateDelay <= 0) {

		//Stone Collisions
		updateCollisions(overWorldMap);
	}
	updateDelay--;
	//Screen Change Logic
	updateScreenChange(overWorldMap);
	attackEnemy(enemyManager);
}