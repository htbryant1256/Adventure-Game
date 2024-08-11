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
	OverWorldMap();
	void render(sf::RenderWindow* window);
	void loadMapLeft();
	void loadMapRight();
	void loadMapUp();
	void loadMapDown();
	int getTileSize();
	void resetMap();
	bool newMapLoaded = false;

	static const int tileMapWidth = 29;
	static const int tileMapHeight = 15;
	char tileMap[tileMapHeight][tileMapWidth];
private:
	void initJsonReader();
	void loadMapFromJson();
	void loadTextures();
	void initObjectTileMap();
	int getMapPositionIndex(int i, int j);

	int mapY = 0;
	int mapX = 0;
	int mapHeight = 0;
	int mapWidth = 0;
	int tileSize = 65;

	Json::Value actualJson;
	Json::Reader reader;
	sf::Texture stoneTexture;
	sf::Texture grassTexture;
	sf::Texture waterTexture;
	sf::Texture woodTexture;
	sf::Texture sandTexture;
	sf::RectangleShape objectTileMap[15][29];
};
