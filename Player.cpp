#include "Player.h"

Player::Player()
{
	posX = 1;
	posY = 1;
	delay = 5;
	//entity.setFillColor(sf::Color(100,150,100));
	
	
	if (!playerTexture.loadFromFile("./Graphics/Tiles/playerTile.png"))
	{
		printf("Error Loading playerTile.png\n");
	}

	playerSprite.setTexture(&playerTexture, false);

	playerDirectionRect.setFillColor(sf::Color(200, 0, 0));
	playerDirectionRect.setSize(sf::Vector2f(10, 25));
	
}

void Player::updateCollisions(OverWorldMap& overWorldMap)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (overWorldMap.tileMap[posY][posX + 1] != 's' && posY + 1 != 38) {
			posX += 1;
			updateDelay = delay;
		}
		direction = EAST;
		playerDirectionRect.setRotation(-90);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (overWorldMap.tileMap[posY][posX - 1] != 's' && posY - 1 != -1) {
			posX -= 1;
			updateDelay = delay;
		}
		direction = WEST;
		playerDirectionRect.setRotation(90);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (overWorldMap.tileMap[posY + 1][posX] != 's' && posY + 1 != 20) {
			posY += 1;
			updateDelay = delay;
		}
		direction = SOUTH;
		playerDirectionRect.setRotation(0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (overWorldMap.tileMap[posY - 1][posX] != 's' && posY - 1 != -1) {
			posY -= 1;
			updateDelay = delay;
		}
		direction = NORTH;
		playerDirectionRect.setRotation(180);
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

void Player::render(sf::RenderWindow* window, OverWorldMap* overWorldMap)
{
	playerSprite.setSize(sf::Vector2f(overWorldMap->getTileSize(), overWorldMap->getTileSize()));
	playerSprite.setPosition(sf::Vector2f(10 + (posX * overWorldMap->getTileSize()), 40 + (posY * overWorldMap->getTileSize())));
	playerDirectionRect.setPosition(sf::Vector2f(playerSprite.getPosition().x + overWorldMap->getTileSize() / 2, playerSprite.getPosition().y + overWorldMap->getTileSize() / 2));
	window->draw(playerSprite);
	//window->draw(playerDirectionRect);
}
