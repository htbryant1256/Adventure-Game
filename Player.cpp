#include "Player.h"

Player::Player()
{
	posX = 1;
	posY = 1;
	delay = 15;
	
	if (!playerTexture.left.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 32, 32, 32)))
	{
		printf("Error Loading playerSpriteSheet.png\n");
	}
	else {
		playerTexture.left1.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 32, 32, 32));
		playerTexture.left2.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(64, 32, 32, 32));
		playerTexture.left3.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(96, 32, 32, 32));
		playerTexture.right.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 0, 32, 32));
		playerTexture.right1.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 0, 32, 32));
		playerTexture.right2.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(64, 0, 32, 32));
		playerTexture.right3.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(96, 0, 32, 32));
		playerTexture.attackLeft.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 64, 32, 32));
		playerTexture.attackRight.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 64, 32, 32));
		playerTexture.attackUp.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(64, 64, 32, 32));
		playerTexture.attackDown.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(96, 64, 32, 32));
		playerTexture.up.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		playerTexture.down.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 96, 32, 32));
	}

	playerSprite.setTexture(&playerTexture.right, false);
}

void Player::updateCollisions(OverWorldMap& overWorldMap)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (overWorldMap.tileMap[posY][posX + 1] != 's' && posY + 1 != 28) {
			moveRight = true;
			updateDelay = delay;
		}
		direction = EAST;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (overWorldMap.tileMap[posY][posX - 1] != 's' && posY - 1 != -1) {
			moveLeft = true;
			updateDelay = delay;
		}
		direction = WEST;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (overWorldMap.tileMap[posY + 1][posX] != 's' && posY + 1 != 15) {
			moveDown = true;
			updateDelay = delay;
		}
		direction = SOUTH;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (overWorldMap.tileMap[posY - 1][posX] != 's' && posY - 1 != -1) {
			moveUp = true;
			updateDelay = delay;
		}
		direction = NORTH;
	}

	if (moveDown && moveLeft) {
		if (overWorldMap.tileMap[posY + 1][posX - 1] == 's') {
			moveLeft = false;
		}
	}if (moveDown && moveRight) {
		if (overWorldMap.tileMap[posY + 1][posX + 1] == 's') {
			moveRight = false;
		}
	}
	if (moveUp && moveRight) {
		if (overWorldMap.tileMap[posY - 1][posX + 1] == 's') {
			moveRight = false;
		}
	}
	if (moveUp && moveLeft) {
		if (overWorldMap.tileMap[posY - 1][posX - 1] == 's') {
			moveLeft = false;
		}
	}
}

void Player::updateScreenChange(OverWorldMap& overWorldMap)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && overWorldMap.tileMap[posY][posX] == 'd' && posX == 28) {
		posX = 0;
		overWorldMap.loadMapRight();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && overWorldMap.tileMap[posY][posX] == 'd' && posX == 0) {
		posX = 28;
		overWorldMap.loadMapLeft();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && overWorldMap.tileMap[posY][posX] == 'd' && posY == 14) {
		posY = 0;
		overWorldMap.loadMapDown();
		updateDelay = delay;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && overWorldMap.tileMap[posY][posX] == 'd' && posY == 0) {
		posY = 14;
		overWorldMap.loadMapUp();
		updateDelay = delay;
	}
}

void Player::animateLeft()
{
	if (animationTimer < (delay / 4)) {
		playerSprite.setTexture(&playerTexture.left, false);
	}
	else if (animationTimer < 2 * (delay / 4)) {
		playerSprite.setTexture(&playerTexture.left1, false);
	}
	else if (animationTimer < 3 * (delay / 4)) {
		playerSprite.setTexture(&playerTexture.left2, false);
	}
	else if (animationTimer < 4 * (delay / 4)) {
		playerSprite.setTexture(&playerTexture.left3, false);
	}
}

void Player::animateRight()
{
	if (animationTimer < (delay / 4)) {
		playerSprite.setTexture(&playerTexture.right2, false);
	}
	else if (animationTimer < 2 *(delay / 4)) {
		playerSprite.setTexture(&playerTexture.right1, false);
	}
	else if (animationTimer < 3 * (delay / 4)) {
		playerSprite.setTexture(&playerTexture.right2, false);
	}
	else if (animationTimer < 4 * (delay / 4)) {
		playerSprite.setTexture(&playerTexture.right3, false);
	}
}

void Player::animateUp()
{
	if (animationTimer == 0) {
		playerSprite.setTexture(&playerTexture.up, false);
	}
	else if (animationTimer < (delay / 4)) {
		playerSprite.setTexture(&playerTexture.up, false);
	}
	else if (animationTimer < 2 * (delay / 4)) {
		playerSprite.setTexture(&playerTexture.up, false);
	}
	else if (animationTimer < 3 * (delay / 4)) {
		playerSprite.setTexture(&playerTexture.up, false);
	}
}

void Player::update(OverWorldMap& overWorldMap)
{
	if (updateDelay <= 0) {
		updateCollisions(overWorldMap);
	}
	if (direction == WEST) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			animateAttackLeft();
		}
		else {
			playerSprite.setTexture(&playerTexture.left, false);
		}
	}else if (direction == EAST) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			animateAttackRight();
		}
		else {
			playerSprite.setTexture(&playerTexture.right, false);
		}
	}
	else if (direction == SOUTH) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			animateAttackDown();
		}
		else {
			playerSprite.setTexture(&playerTexture.down, false);
		}
	}
	else if (direction == NORTH) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			animateAttackUp();
		}
		else {
			playerSprite.setTexture(&playerTexture.up, false);
		}
	}


	if (moveRight && moveUp) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(50/delay, -50 / delay));

		animateRight();

		if (animationTimer <= 0) {
			moveRight = false;
			moveUp = false;
			posY -= 1;
			posX += 1;
			animationTimer = delay;
		}
	}
	else if (moveRight && moveDown) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(50 / delay, 50 / delay));

		animateRight();

		if (animationTimer <= 0) {
			moveRight = false;
			moveDown = false;
			posY += 1;
			posX += 1;
			animationTimer = delay;
		}
	}
	else if (moveLeft && moveDown) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(-50 / delay, 50 / delay));
		animateLeft();
		if (animationTimer <= 0) {
			moveLeft = false;
			moveDown = false;
			posY += 1;
			posX -= 1;
			animationTimer = delay;
		}
	}
	else if (moveLeft && moveUp) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(-50 / delay, -50 / delay));
		animateLeft();
		if (animationTimer <= 0) {
			moveLeft = false;
			moveUp = false;
			posY -= 1;
			posX -= 1;
			animationTimer = delay;
		}
	}
	else if (moveLeft) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(-50 / delay, 0));
		
		animateLeft();
		

		if (animationTimer <= 0) {
			moveLeft = false;
			posX -= 1;
			animationTimer = delay;
		}
	}
	else if (moveRight) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(50 / delay, 0));

		animateRight();

		if (animationTimer <= 0) {
			moveRight = false;
			posX += 1;
			animationTimer = delay;
		}
	}
	else if (moveUp) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(0, -50 / delay));

		animateUp();

		if (animationTimer <= 0) {
			moveUp = false;
			posY -= 1;
			animationTimer = delay;
		}
	}
	else if (moveDown) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(0, 50 / delay));

		animateDown();

		if (animationTimer <= 0) {
			moveDown = false;
			posY += 1;
			animationTimer = delay;
		}
	}
	updateDelay--;
	//Screen Change Logic
	updateScreenChange(overWorldMap);
	
}

void Player::animateDown()
{
	if (animationTimer == 0) {
		playerSprite.setTexture(&playerTexture.down, false);
	}
	else if (animationTimer < (delay / 4)) {
		playerSprite.setTexture(&playerTexture.down, false);
	}
	else if (animationTimer < 2 * (delay / 4)) {
		playerSprite.setTexture(&playerTexture.down, false);
	}
	else if (animationTimer < 3 * (delay / 4)) {
		playerSprite.setTexture(&playerTexture.down, false);
	}
}

void Player::animateAttackLeft()
{
	playerSprite.setTexture(&playerTexture.attackLeft, false);
	
}

void Player::animateAttackRight()
{
	playerSprite.setTexture(&playerTexture.attackRight, false);
}

void Player::animateAttackUp()
{
	playerSprite.setTexture(&playerTexture.attackUp, false);
}

void Player::animateAttackDown()
{
	playerSprite.setTexture(&playerTexture.attackDown, false);
}

void Player::render(sf::RenderWindow* window, OverWorldMap* overWorldMap)
{
	playerSprite.setSize(sf::Vector2f(overWorldMap->getTileSize(), overWorldMap->getTileSize()));
	if (!moveRight && !moveLeft && !moveDown && !moveUp) {
		playerSprite.setPosition(sf::Vector2f(10 + (posX * overWorldMap->getTileSize()), 40 + (posY * overWorldMap->getTileSize())));
	}
	
	playerDirectionRect.setPosition(sf::Vector2f(playerSprite.getPosition().x + overWorldMap->getTileSize() / 2, playerSprite.getPosition().y + overWorldMap->getTileSize() / 2));
	window->draw(playerSprite);
	//window->draw(playerDirectionRect);
}
