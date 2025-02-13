#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

#include "OverWorldMap.h"
#include "Player.h"
#include "EnemyManager.h"
#include "EnemyPlayerInteraction.h"
#include "HUD.h"
#include "DeathScreen.h"
class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
  
	OverWorldMap overWorldMap;
	Player player;
	EnemyManager enemyManager;
	EnemyPlayerInteraction enemyPlayerInteraction;
	DeathScreen deathScreen;
	HUD hud;

	int windowHeight;
	int windowWidth;
	int screenTimer = 43;
	void initVariables();
	void initWindow();
	void pollEvents();
public:
	Game();
	~Game();
	
	void update();
	void render();
};

#endif