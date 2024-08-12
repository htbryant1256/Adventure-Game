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
    void animateLeft();
    void animateRight();
    void animateUp();
    void animateDown();
    void animateAttack();

    void animate(sf::Texture texture[4]);
    void movePlayer();
    void initTextures();
    sf::RectangleShape playerSprite;

    typedef struct playerTexture {
        sf::Texture attackLeft;
        sf::Texture attackRight;
        sf::Texture attackUp;
        sf::Texture attackDown;
        sf::Texture right[4];
        sf::Texture left[4];
        sf::Texture down[4];
        sf::Texture up[4];

    }PlayerTexture;

    PlayerTexture playerTexture;


    sf::RectangleShape playerDirectionRect;
    bool moveRight = false;
    bool moveLeft = false;
    bool moveUp = false;
    bool moveDown = false;
    int animationTimer = delay;
    int totalHealth = 100;
    int playerStartingPosX = 15;
    int playerStartingPosY = 8;
};

