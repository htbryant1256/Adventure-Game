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
    void animateLeft();
    void animateRight();
    void animateUp();
    void animateDown();
    void animateAttackLeft();
    void animateAttackRight();
    void animateAttackUp();
    void animateAttackDown();
    sf::RectangleShape playerSprite;

    typedef struct playerTexture {
        sf::Texture right;
        sf::Texture right1;
        sf::Texture right2;
        sf::Texture right3;
        sf::Texture left;
        sf::Texture left1;
        sf::Texture left2;
        sf::Texture left3;
        sf::Texture down;
        sf::Texture up;
        sf::Texture attackLeft;
        sf::Texture attackRight;
        sf::Texture attackUp;
        sf::Texture attackDown;

    }PlayerTexture;

    PlayerTexture playerTexture;


    sf::RectangleShape playerDirectionRect;
    bool moveRight = false;
    bool moveLeft = false;
    bool moveUp = false;
    bool moveDown = false;
    int animationTimer = delay;
};

