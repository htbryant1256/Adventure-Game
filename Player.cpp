#include "Player.h"

Player::Player()
{
	delay = 8;
	resetPlayer();
	initTextures();
}

void Player::updateCollisions(OverWorldMap& overWorldMap)
{
	if (updateDelay <= 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (overWorldMap.tileMap[posY][posX + 1] < 3 && posX + 1 != 29) {
				moveRight = true;
				updateDelay = delay;
			}
			direction = EAST;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (overWorldMap.tileMap[posY][posX - 1] < 3 && posX - 1 != -1) {
				moveLeft = true;
				updateDelay = delay;
			}
			direction = WEST;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (overWorldMap.tileMap[posY + 1][posX] < 3 && posY + 1 != 15) {
				moveDown = true;
				updateDelay = delay;
			}
			direction = SOUTH;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (overWorldMap.tileMap[posY - 1][posX] < 3 && posY - 1 != -1) {
				moveUp = true;
				updateDelay = delay;
			}
			direction = NORTH;
		}

		if (moveDown && moveLeft) {
			if (overWorldMap.tileMap[posY + 1][posX - 1] >= 3) {
				moveLeft = false;
			}
		}if (moveDown && moveRight) {
			if (overWorldMap.tileMap[posY + 1][posX + 1] >= 3) {
				moveRight = false;
			}
		}
		if (moveUp && moveRight) {
			if (overWorldMap.tileMap[posY - 1][posX + 1] >= 3) {
				moveRight = false;
			}
		}
		if (moveUp && moveLeft) {
			if (overWorldMap.tileMap[posY - 1][posX - 1] >= 3) {
				moveLeft = false;
			}
		}
	}
}

void Player::updateScreenChange(OverWorldMap& overWorldMap)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)  && posX == 28) {
		posX = 0;
		overWorldMap.loadMapRight();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && posX == 0) {
		posX = 28;
		overWorldMap.loadMapLeft();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && posY == 14) {
		posY = 0;
		overWorldMap.loadMapDown();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && posY == 0) {
		posY = 14;
		overWorldMap.loadMapUp();
		updateDelay = delay;
	}
}

void Player::update(OverWorldMap& overWorldMap)
{
	updateCollisions(overWorldMap);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		animateAttack();
	}
	else {
		if (direction == WEST) {
			entitySprite.setTexture(&entityTexture.left[0], false);
		}
		else if (direction == EAST) {
			entitySprite.setTexture(&entityTexture.right[0], false);
		}
		else if (direction == SOUTH) {
			entitySprite.setTexture(&entityTexture.down[0], false);
		}
		else if (direction == NORTH) {
			entitySprite.setTexture(&entityTexture.up[0], false);
		}
	}
	
//TODO This logic is bogus, add animations inside of the movePlayer function.
	if (moveLeft) {
		animateLeft();
		movePlayer();
	}
	else if (moveRight) {
		animateRight();
		movePlayer();
	}
	else if (moveUp) {
		animateUp();
		movePlayer();
	}
	else if (moveDown) {
		animateDown();
		movePlayer();
	}
	
	updateScreenChange(overWorldMap);
	updateDelay--;
// TODO make this a function for damageAnimation.
	if (hit == true) {
		health -= 5;
		entitySprite.setFillColor(sf::Color(255, 0, 0));
		hit = false;
	}
	else {
		entitySprite.setFillColor(sf::Color(255, 255, 255));
	}
}

void Player::animateAttack()
{
	if (direction == WEST) {
		entitySprite.setTexture(&entityTexture.attackLeft, false);
	}
	else if (direction == EAST) {
		entitySprite.setTexture(&entityTexture.attackRight, false);
	}
	else if (direction == SOUTH) {
		entitySprite.setTexture(&entityTexture.attackDown, false);
	}
	else if (direction == NORTH) {
		entitySprite.setTexture(&entityTexture.attackUp, false);
	}
}

void Player::movePlayer()
{
	if (moveRight) {
		entitySprite.move(sf::Vector2f(50 / delay, 0));
		if (animationTimer <= 0) {
			moveRight = false;
			posX += 1;
		}
	}
	if (moveLeft) {
		entitySprite.move(sf::Vector2f(-50 / delay, 0));
		if (animationTimer <= 0) {
			moveLeft = false;
			posX -= 1;
		}
	}
	if (moveUp) {
		entitySprite.move(sf::Vector2f(0, -50 / delay));
		if (animationTimer <= 0) {
			moveUp = false;
			posY -= 1;
		}
	}
	if (moveDown) {
		entitySprite.move(sf::Vector2f(0, 50 / delay));
		if (animationTimer <= 0) {
			moveDown = false;
			posY += 1;
		}
	}
	if (animationTimer <= 0) {
		animationTimer = delay;
	}
}

void Player::initTextures()
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

void Player::render(sf::RenderWindow* window, OverWorldMap* overWorldMap)
{
	//Remove the setSize here, it is ridiculous and expensive to run.
	entitySprite.setSize(sf::Vector2f(overWorldMap->getTileSize(), overWorldMap->getTileSize()));
	if (!moveRight && !moveLeft && !moveDown && !moveUp) {
		entitySprite.setPosition(sf::Vector2f(10 + (posX * overWorldMap->getTileSize()), 40 + (posY * overWorldMap->getTileSize())));
	}
	window->draw(entitySprite);
}

void Player::resetPlayer()
{
	health = totalHealth;
	posX = playerStartingPosX;
	posY = playerStartingPosY;
}
