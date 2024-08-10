#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "json/value.h"
#include "json/json.h"
#include <fstream> 

class OverWorldMap
{
public:
	void render(sf::RenderWindow* window);
	void initOverWorldMap();
	void loadMapLeft();
	void loadMapRight();
	void loadMapUp();
	void loadMapDown();
	int getTileSize();
	bool newMapLoaded = false;
	char tileMap[15][29];
private:
	void initJsonReader();
	void loadMapFromJson();
	void loadTextures();
	void initObjectTileMap();

	int mapY = 0;
	int mapX = 0;
	int mapHeight = 0;
	int mapWidth = 0;
	int tileSize = 65;

	Json::Value actualJson;
	Json::Reader reader;
	sf::Texture stoneTexture;
	sf::Texture grassTexture;
	sf::Texture doorTexture;
	sf::RectangleShape objectTileMap[15][29];
};

