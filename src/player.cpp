#include "player.hpp"
#include <SFML/Graphics.hpp>

Player::Player(float width, float height)
{
	player.setScale(width, height);
	if (!normalTexture.loadFromFile("content/normal.png"))
	{
		std::cout << "ERROR: Could not load player texture";
	}

	if (!firedTexture.loadFromFile("content/fired.png"))
	{
		std::cout << "ERROR: Could not load player texture";
	}
	player.setTexture(normalTexture);
	player.setScale(width, height);
	player.setOrigin(16, 16);
	player.setPosition(x, y);
}

void Player::movePlayer(float dt)
{
	int angle = player.getRotation() * (M_PI / 180);
	// Accelerate on button press
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// Flicker engine when holding w or up
		switchTexture += 5;
		if (switchTexture % 6 == 0)
		{
			player.setTexture(firedTexture);
		}
		else
		{
			player.setTexture(normalTexture);
		}

		while (acceleration.y <= 2.0f)
		{
			acceleration.y += acc;
			acceleration.x += acc;
		}
		velocity += acceleration;
		velocity = 0.40f * velocity;
		direction.x += velocity.x * cos(angle);
		direction.y += velocity.y * sin(angle);
	}
	// Decelerate on button release
	else
	{
		player.setTexture(normalTexture);
		switchTexture = 0;

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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player.rotate(-5);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player.rotate(5);
	}

	// Move in direction player is pointed
	player.move(direction * dt);
}

void Player::screenWrapping(int& screenWidth, int& screenHeight)
{
	// If player goes beyond x bounds set position to opposite site of screen
	if (player.getPosition().x > screenWidth)
	{
		player.setPosition(0, player.getPosition().y);
	}
	else if (player.getPosition().x <= 0)
	{
		player.setPosition(screenWidth, player.getPosition().y);
	}

	// If player goes beyond y bounds set position to opposite site of screen
	if (player.getPosition().y >= screenHeight)
	{
		player.setPosition(player.getPosition().x, 0);
	}
	else if (player.getPosition().y <= 0)
	{
		player.setPosition(player.getPosition().x, screenHeight);
	}
}

int Player::returnX()
{
	return player.getPosition().x;
}

int Player::returnY()
{
	return player.getPosition().y;
}

int Player::returnAngle()
{
	return player.getRotation();
}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw(player);
}