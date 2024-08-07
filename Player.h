#pragma once
#include "Entity.h"
class Player :
    public Entity
{
public:
    void update(OverWorldMap& overWorldMap);
    void render(sf::RenderWindow* window, OverWorldMap* overWorldMap);
    Player();
private:
    void updateCollisions(OverWorldMap& overWorldMap);
    void updateScreenChange(OverWorldMap& overWorldMap);
    sf::RectangleShape playerSprite;
    sf::Texture playerTexture;
    sf::Texture playerTextureLeft;
    sf::Texture playerTextureLeft2;
    sf::Texture playerTextureLeft3;
    sf::Texture playerTextureLeft4;

    sf::Texture playerTextureRight2;
    sf::Texture playerTextureRight3;
    sf::Texture playerTextureRight4;

    sf::RectangleShape playerDirectionRect;
    bool moveRight = false;
    bool moveLeft = false;
    bool moveUp = false;
    bool moveDown = false;
    int animationTimer = delay;
};

