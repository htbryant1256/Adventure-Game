#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "OverWorldMap.h"
class Entity
{
public:
	int posY;
	int posX;

	int delay;
	int updateDelay = delay;
	int animationTimer = delay;

	int attackDelay;

	enum Direction {
		NORTH = 1,
		EAST = 2,
		SOUTH = 3,
		WEST = 4,
	};
	Direction direction;
	bool moveRight = false;
	bool moveLeft = false;
	bool moveUp = false;
	bool moveDown = false;
	int health;
	bool hit = false;
	void moveEntity();

	typedef struct entityTexture {
		sf::Texture attackLeft;
		sf::Texture attackRight;
		sf::Texture attackUp;
		sf::Texture attackDown;
		sf::Texture right[4];
		sf::Texture left[4];
		sf::Texture down[4];
		sf::Texture up[4];

	}EntityTexture;

	EntityTexture entityTexture;
	sf::RectangleShape entitySprite;
	void animate(sf::Texture texture[4]);
	void animateLeft();
	void animateRight();
	void animateUp();
	void animateDown();
	void render(sf::RenderWindow* window);
	void animateAttack();
private:


};

