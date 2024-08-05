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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && overWorldMap.tileMap[posY][posX + 1] != 's' && posY + 1 != 19) {
		posX += 1;
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && overWorldMap.tileMap[posY][posX - 1] != 's' && posY - 1 != -1) {
		posX -= 1;
		updateDelay = delay;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && overWorldMap.tileMap[posY + 1][posX] != 's' && posY + 1 != 10) {
		posY += 1;
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && overWorldMap.tileMap[posY - 1][posX] != 's' && posY - 1 != -1) {
		posY -= 1;
		updateDelay = delay;
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

void Player::update(OverWorldMap& overWorldMap)
{
	if (updateDelay <= 0) {

		//Stone Collisions
		updateCollisions(overWorldMap);
	}
	updateDelay--;
	//Screen Change Logic
	updateScreenChange(overWorldMap);
}