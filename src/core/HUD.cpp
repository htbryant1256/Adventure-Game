#include "HUD.h"

void HUD::render(sf::RenderWindow* window)
{
	
	window->draw(healthBarBackground);
	window->draw(healthBar);
}

void HUD::update(Player& player)
{
	if (player.health >= 0) {
		healthBar.setSize(sf::Vector2f(490 * (player.health / 100.f), 30));
	}
	else {
		healthBar.setSize(sf::Vector2f(0, 30));
	}
	

}

HUD::HUD()
{
	healthBarBackground.setPosition(sf::Vector2f(10, 10));
	healthBarBackground.setFillColor(sf::Color::Black);
	healthBarBackground.setSize(sf::Vector2f(500, 40));
	healthBarBackground.setOutlineThickness(1);

	healthBar.setPosition(sf::Vector2f(15, 15));
	healthBar.setFillColor(sf::Color::Green);
	healthBar.setSize(sf::Vector2f(490, 30));
	healthBar.setOutlineThickness(1);
}
