#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
class OverWorldMap
{
public:
	void render(sf::RenderWindow* window);
	void initOverWorldMap();
	void initMapArray();
	int getTileSize();
	char tileMap[10][19] = {
		{ 's','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s' },
		{ 's','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s' },
		{ 's','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s' },
		{ 's','g','g','g','s','s','s','s','g','g','g','g','g','g','g','g','g','g','s' },
		{ 's','g','g','g','s','g','g','s','g','g','g','g','g','g','g','g','g','g','s' },
		{ 's','g','g','g','s','g','g','s','g','g','g','g','g','g','g','g','g','g','s' },
		{ 's','g','g','g','s','s','s','s','g','g','g','g','g','g','g','g','g','g','d' },
		{ 's','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s' },
		{ 's','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s' },
		{ 's','s','s','s','s','d','s','s','s','s','s','s','s','s','s','s','s','s','s' } };

	void loadMapLeft();
	void loadMapRight();
	void loadMapUp();
	void loadMapDown();
	bool newMapLoaded = false;
private:
	int mapPosX, mapPosY;
	char map1[10][19] = {
		{'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','s','s','s','s','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','s','g','g','s','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','s','g','g','s','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','s','s','s','s','g','g','g','g','g','g','g','g','g','g','d'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','s','s','s','s','d','s','s','s','s','s','s','s','s','s','s','s','s','s'} };

	char map2[10][19] = {
		{'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','s','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','s','g','g','g','s'},
		{'d','g','g','g','g','g','g','g','g','g','g','g','g','s','s','s','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','d','s','s','s'} };

	char map3[10][19] = {
		{'s','s','s','s','s','d','s','s','s','s','s','s','s','s','s','s','s','s','s'},
		{'s','g','g','g','g','g','g','s','s','s','s','s','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','d'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','s','s','s','s','s','s','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','s','g','g','g','g','s','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','s','g','g','g','g','s','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','s','g','g','g','g','s','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','s','g','g','g','g','s','g','g','g','g','g','s'},
		{'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'} };

	char map4[10][19] = {
		{'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','d','s','s','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'d','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','g','s'},
		{'s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s'} };

	char mapArray[2][2][10][19];

	int tileSize = 100;
	sf::RectangleShape objectTileMap[10][19];

	


};

