#pragma once
#include "Entity.h"
class Player :
    public Entity
{
public:
    void update(OverWorldMap& overWorldMap);
    void render(sf::RenderWindow* window, OverWorldMap* overWorldMap);
    void resetPlayer();
    Player();
private:
    void updateCollisions(OverWorldMap& overWorldMap);
    void updateScreenChange(OverWorldMap& overWorldMap);

    void animateAttack();

 //   void animate(sf::Texture texture[4]);
    void movePlayer();
    void initTextures();




    sf::RectangleShape playerDirectionRect;
    bool moveRight = false;
    bool moveLeft = false;
    bool moveUp = false;
    bool moveDown = false;
    int totalHealth = 100;
    int playerStartingPosX = 15;
    int playerStartingPosY = 8;
};

