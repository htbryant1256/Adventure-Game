#include "Enemy.h"
 
Enemy::Enemy(int x, int y)
{
	posX = x;
	posY = y;
	delay = 25;
	seekingDistance = 10;
	srand(time(NULL));
	health = 5;
	entitySprite.setSize(sf::Vector2f(OverWorldMap::getTileSize(), OverWorldMap::getTileSize()));
	initTextures();
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
		entitySprite.setFillColor(sf::Color(100,100,100));
	}
	else {
		entitySprite.setFillColor(sf::Color::White);
	}


	if (moveLeft) {
		animateLeft();
		moveEntity();
	}
	else if (moveRight) {
		animateRight();
		moveEntity();
	}
	else if (moveUp) {
		animateUp();
		moveEntity();
	}
	else if (moveDown) {
		animateDown();
		moveEntity();
	}
	if (!moveRight && !moveLeft && !moveDown && !moveUp) {
		entitySprite.setPosition(sf::Vector2f(10 + (posX * OverWorldMap::getTileSize()), 40 + (posY * OverWorldMap::getTileSize())));
	}
}

void Enemy::seekPlayer(OverWorldMap& overWorldMap, int playerPosX, int playerPosY)
{
	if (playerPosX > posX && overWorldMap.tileMap[posY][posX + 1] < 3 && posX + 1 != playerPosX) {
		moveRight = true;
	}
	else if (playerPosX < posX && overWorldMap.tileMap[posY][posX - 1] < 3 && posX +- 1 != playerPosX) {
		moveLeft = true;
	}
	if (playerPosY > posY && overWorldMap.tileMap[posY + 1][posX] < 3 && posY + 1 != playerPosY) {
		moveDown = true;
	}
	else if (playerPosY < posY && overWorldMap.tileMap[posY - 1][posX] < 3 && posY - 1 != playerPosY) {
		moveUp = true;
	}
	updateDelay = delay;
}

void Enemy::randomlyWalk(OverWorldMap& overWorldMap)
{
	int movement = rand() % 4 + 1;
	if (movement == 1 && overWorldMap.tileMap[posY][posX + 1] < 3) {
		moveRight = true;
	}
	if (movement == 2 && overWorldMap.tileMap[posY][posX - 1] < 3) {
		moveLeft = true;
	}
	if (movement == 3 && overWorldMap.tileMap[posY + 1][posX] < 3) {
		moveDown = true;
	}
	if (movement == 4 && overWorldMap.tileMap[posY - 1][posX] <= 3) {
		moveUp = true;
	}
	updateDelay = delay;
}

void Enemy::initTextures()
{
	if (!entityTexture.left[0].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 32, 32, 32)))
	{
		printf("Error Loading playerSpriteSheet.png\n");
	}
	else {
		entityTexture.left[1].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 32, 32, 32));
		entityTexture.left[2].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(64, 32, 32, 32));
		entityTexture.left[3].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(96, 32, 32, 32));
		entityTexture.right[0].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 0, 32, 32));
		entityTexture.right[1].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 0, 32, 32));
		entityTexture.right[2].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(64, 0, 32, 32));
		entityTexture.right[3].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(96, 0, 32, 32));
		entityTexture.up[0].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		entityTexture.up[1].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		entityTexture.up[2].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		entityTexture.up[3].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		entityTexture.down[0].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 96, 32, 32));
		entityTexture.down[1].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 96, 32, 32));
		entityTexture.down[2].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 96, 32, 32));
		entityTexture.down[3].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 96, 32, 32));
		entityTexture.attackLeft.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 64, 32, 32));
		entityTexture.attackRight.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 64, 32, 32));
		entityTexture.attackUp.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(64, 64, 32, 32));
		entityTexture.attackDown.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(96, 64, 32, 32));
	}
	entitySprite.setTexture(&entityTexture.right[0], false);
}
