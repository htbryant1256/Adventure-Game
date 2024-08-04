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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && overWorldMap.tileMap[posY][posX + 1] != 's') {
		posX += 1;
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && overWorldMap.tileMap[posY][posX - 1] != 's') {
		posX -= 1;
		updateDelay = delay;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && overWorldMap.tileMap[posY + 1][posX] != 's') {
		posY += 1;
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && overWorldMap.tileMap[posY - 1][posX] != 's') {
		posY -= 1;
		updateDelay = delay;
	}
}

void Player::updateScreenChange(OverWorldMap& overWorldMap)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && overWorldMap.tileMap[posY][posX] == 'd' && posX == 18) {
		overWorldMap.loadMapRight();
		posX = 0;
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && overWorldMap.tileMap[posY][posX] == 'd' && posX == 0) {
		overWorldMap.loadMapLeft();
		posX = 18;
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && overWorldMap.tileMap[posY][posX] == 'd' && posY == 9) {
		overWorldMap.loadMapDown();
		posY = 0;
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && overWorldMap.tileMap[posY][posX] == 'd' && posY == 0) {
		overWorldMap.loadMapUp();
		posY = 9;
		updateDelay = delay;
	}
}

void Player::update(OverWorldMap& overWorldMap)
{
	if (updateDelay <= 0) {

		//Stone Collisions
		updateCollisions(overWorldMap);

		//Screen Change Logic
		updateScreenChange(overWorldMap);

	}
	updateDelay--;
}