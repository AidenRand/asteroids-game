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

void Player::movePlayer(float dt)
{
	auto angle = player.getRotation() * (M_PI / 180);

	// Accelerate on button press
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		while (acceleration.y <= 3.0f)
		{
			acceleration.y += acc;
			acceleration.x += acc;
		}
		velocity += acceleration;

		velocity = 0.99f * velocity;
	}
	// Decelerate on button release
	else
	{
		velocity.x -= dAcc;
		velocity.y -= dAcc;
		if (velocity.x <= 0.3f)
		{
			velocity.x = 0;
		}

		if (velocity.y <= 0.3f)
		{
			velocity.y = 0;
		}
	}

	// Move in direction player is pointed
	direction.x = velocity.x * cos(angle);
	direction.y = velocity.y * sin(angle);
	player.move(direction.x * dt, direction.y * dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.rotate(-6);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.rotate(6);
	}
}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw(player);
}