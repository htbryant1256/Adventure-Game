#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "Player.h"
class HUD
{
public:
	void render(sf::RenderWindow* window);
	void update(Player& player);
	HUD();
private:
	sf::RectangleShape healthBarBackground;
	sf::RectangleShape healthBar;

};

