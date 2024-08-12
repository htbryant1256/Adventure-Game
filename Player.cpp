#include "Player.h"

Player::Player()
{
	posX = 15;
	posY = 8;
	delay = 5;
	health = 100;
	initTextures();
}

void Player::updateCollisions(OverWorldMap& overWorldMap)
{
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

	if (updateDelay <= 0) {
		updateCollisions(overWorldMap);
	}
	animateAttack();

	if (moveRight && moveUp) {
		animationTimer--;
		playerSprite.move(sf::Vector2f(50/delay, -50/delay));
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
	if (hit == true) {
		health -= 5;
		playerSprite.setFillColor(sf::Color(255, 0, 0));
		hit = false;
	}
	else {
		playerSprite.setFillColor(sf::Color(255, 255, 255));
	}
	
}

void Player::animateLeft()
{
	animateMovement(playerTexture.left);
}

void Player::animateRight()
{
	animateMovement(playerTexture.right);
}

void Player::animateUp()
{
	animateMovement(playerTexture.up);
}

void Player::animateDown()
{
	animateMovement(playerTexture.down);
}

void Player::animateAttack()
{
	if (direction == WEST) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			playerSprite.setTexture(&playerTexture.attackLeft, false);
		}
		else {
			playerSprite.setTexture(&playerTexture.left[0], false);
		}
	}
	else if (direction == EAST) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			playerSprite.setTexture(&playerTexture.attackRight, false);
		}
		else {
			playerSprite.setTexture(&playerTexture.right[0], false);
		}
	}
	else if (direction == SOUTH) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			playerSprite.setTexture(&playerTexture.attackDown, false);
		}
		else {
			playerSprite.setTexture(&playerTexture.down[0], false);
		}
	}
	else if (direction == NORTH) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			playerSprite.setTexture(&playerTexture.attackUp, false);
		}
		else {
			playerSprite.setTexture(&playerTexture.up[0], false);
		}
	}
}


void Player::animateMovement(sf::Texture texture[4])
{
	if (animationTimer < (delay / 4)) {
		playerSprite.setTexture(&texture[0], false);
	}
	else if (animationTimer < 2 * (delay / 4)) {
		playerSprite.setTexture(&texture[1], false);
	}
	else if (animationTimer < 3 * (delay / 4)) {
		playerSprite.setTexture(&texture[2], false);
	}
	else if (animationTimer < 4 * (delay / 4)) {
		playerSprite.setTexture(&texture[3], false);
	}
}

void Player::initTextures()
{
	if (!playerTexture.left[0].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 32, 32, 32)))
	{
		printf("Error Loading playerSpriteSheet.png\n");
	}
	else {
		playerTexture.left[1].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 32, 32, 32));
		playerTexture.left[2].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(64, 32, 32, 32));
		playerTexture.left[3].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(96, 32, 32, 32));
		playerTexture.right[0].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 0, 32, 32));
		playerTexture.right[1].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 0, 32, 32));
		playerTexture.right[2].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(64, 0, 32, 32));
		playerTexture.right[3].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(96, 0, 32, 32));
		playerTexture.up[0].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		playerTexture.up[1].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		playerTexture.up[2].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		playerTexture.up[3].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		playerTexture.down[0].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		playerTexture.down[1].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		playerTexture.down[2].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		playerTexture.down[3].loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 96, 32, 32));
		playerTexture.attackLeft.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(0, 64, 32, 32));
		playerTexture.attackRight.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(32, 64, 32, 32));
		playerTexture.attackUp.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(64, 64, 32, 32));
		playerTexture.attackDown.loadFromFile("./Graphics/Tiles/playerSpriteSheet.png", sf::IntRect(96, 64, 32, 32));
	}
	playerSprite.setTexture(&playerTexture.right[0], false);
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

void Player::resetPlayer()
{
	health = 100;
	posX = 15;
	posY = 8;
}
