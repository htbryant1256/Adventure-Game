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
    sf::RectangleShape playerDirectionRect;
};

