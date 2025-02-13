#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "Player.h"

class DeathScreen
{
public:
	void render(sf::RenderWindow* window);
	void update(Player& player, OverWorldMap& overWorldMap);
	DeathScreen();
private:
	void restartGame(Player& player, OverWorldMap& overWorldMap);
	sf::Font deathFont;
	sf::Text deathText;
};

