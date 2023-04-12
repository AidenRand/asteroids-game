#include "player.hpp"
#include <SFML/Graphics.hpp>

Player::Player(float width, float height, float x, float y)
{
	player.setScale(width, height);
	if (!texture.loadFromFile("content/up-arrow.png"))
	{
		std::cout << "Could not load player texture";
	}
	player.setTexture(texture);
	player.setScale(width, height);
	player.setOrigin(16, 16);
	player.setPosition(x, y);
}

void Player::movePlayer(sf::Keyboard::Key key, bool checkPressed)
{
	if (key == sf::Keyboard::Left)
	{
		rotateLeft = true;
		std::cout << "left";
	}
	else if (key == sf::Keyboard::Right)
	{
		rotateRight = true;
		std::cout << "right";
	}

	if (!checkPressed)
	{
		rotateLeft = false;
		rotateRight = false;
	}
}

void Player::update()
{
	if (rotateLeft)
	{
		player.rotate(-10);
	}
	else if (rotateRight)
	{
		player.rotate(10);
	}
}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw(player);
}