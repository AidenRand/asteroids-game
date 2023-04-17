#include "player.hpp"
#include <SFML/Graphics.hpp>

Player::Player(float width, float height, float x, float y)
{
	player.setScale(width, height);
	if (!normalTexture.loadFromFile("content/normal.png"))
	{
		std::cout << "Could not load player texture";
	}

	if (!firedTexture.loadFromFile("content/fired.png"))
	{
		std::cout << "Could not load player texture";
	}
	player.setTexture(normalTexture);
	player.setScale(width, height);
	player.setOrigin(16, 16);
	player.setPosition(x, y);
}

void Player::movePlayer(float dt)
{
	auto angle = player.getRotation() * (M_PI / 180);

	// Accelerate on button press
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.setTexture(firedTexture);

		while (acceleration.y <= 3.0f)
		{
			acceleration.y += acc;
			acceleration.x += acc;
		}
		velocity += acceleration;
		velocity = 0.39f * velocity;
		direction.x += velocity.x * cos(angle);
		direction.y += velocity.y * sin(angle);
	}
	// Decelerate on button release
	else
	{
		player.setTexture(normalTexture);

		velocity -= acceleration;
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
	player.move(direction * dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.rotate(-6);
		velocity.x -= dAcc;
		velocity.y -= dAcc;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.rotate(6);
		velocity.x -= dAcc;
		velocity.y -= dAcc;
	}
}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw(player);
}