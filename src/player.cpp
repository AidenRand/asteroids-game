#include "player.hpp"
#include <SFML/Graphics.hpp>

Player::Player(float width, float height, float x, float y)
{
	player.setScale(width, height);
	if (!texture.loadFromFile("content/right-arrow.png"))
	{
		std::cout << "Could not load player texture";
	}
	player.setTexture(texture);
	player.setScale(width, height);
	player.setOrigin(width / 2, height / 2);
	player.setPosition(x, y);
}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw(player);
}