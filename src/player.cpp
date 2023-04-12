#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>

Player::Player(float width, float height, float x, float y)
{
	player.setScale(width, height);
	if (!texture.loadFromFile("content/right-arrow.png"))
	{
		std::cout << "Could not load player texture";
	}
	player.setTexture(texture);
	player.setScale(width, height);
	player.setOrigin(12, 12);
	player.setPosition(x, y);
	player.setRotation(-90);
}

void Player::movePlayer(sf::Keyboard::Key key, bool checkPressed)
{
	if (key == sf::Keyboard::Up)
	{
		moveForward = true;
	}
	else if (key == sf::Keyboard::Left)
	{
		rotateLeft = true;
	}
	else if (key == sf::Keyboard::Right)
	{
		rotateRight = true;
	}

	if (!checkPressed)
	{
		rotateLeft = false;
		rotateRight = false;
		moveForward = false;
	}
}

void Player::update()
{
	float movementSpeed = 5;
	sf::Vector2f direction;
	auto angle = player.getRotation() * (M_PI / 180);
	if (moveForward)
	{
		direction.x = movementSpeed * cos(angle);
		direction.y = movementSpeed * sin(angle);
		player.move(direction.x, direction.y);
	}
	else if (rotateLeft)
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