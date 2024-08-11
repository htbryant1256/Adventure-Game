#include "DeathScreen.h"

void DeathScreen::render(sf::RenderWindow* window)
{
    window->draw(deathText);
}

void DeathScreen::restartGame(Player& player, OverWorldMap& overWorldMap)
{
    player.resetPlayer();
    overWorldMap.resetMap();
}

void DeathScreen::update(Player& player, OverWorldMap& overWorldMap)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        restartGame(player, overWorldMap);
    }   
}

DeathScreen::DeathScreen()
{
    if (!deathFont.loadFromFile("arial.ttf"))
    {
        printf("Error\n");
    }

    deathText.setFont(deathFont);

    deathText.setString("You Died");

    deathText.setCharacterSize(60);

    deathText.setFillColor(sf::Color::Red);

    deathText.setStyle(sf::Text::Bold);
    deathText.setPosition(sf::Vector2f(1920 / 2, 1080 / 2));
}
