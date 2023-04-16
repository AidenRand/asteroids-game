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
	player.setOrigin(12, 12);
	player.setPosition(x, y);
	player.setRotation(-90);
}

void Player::movePlayer()
{
	sf::Vector2f direction;
	auto angle = player.getRotation() * (M_PI / 180);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		while (acceleration.y <= 0.5f)
		{
			acceleration.x += 0.05f;
			acceleration.y += 0.05f;
			velocity += acceleration;
		}

		direction.x = velocity.x * cos(angle);
		direction.y = velocity.y * sin(angle);
		player.move(direction.x, direction.y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.rotate(-6);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.rotate(6);
	}
}

void Player::update()
{
	sf::Vector2f direction;
	auto angle = player.getRotation() * (M_PI / 180);
	if (moveForward)
	{
		while (acceleration.y <= 0.5f)
		{
			acceleration.x += 0.05f;
			acceleration.y += 0.05f;
			velocity += acceleration;
		}

		direction.x = velocity.x * cos(angle);
		direction.y = velocity.y * sin(angle);
		player.move(direction.x, direction.y);
	}

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