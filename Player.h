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
    sf::RectangleShape playerDirectionRect;
    bool moveRight = false;
    bool moveLeft = false;
    bool moveUp = false;
    bool moveDown = false;
    int animationTimer = delay;
};

