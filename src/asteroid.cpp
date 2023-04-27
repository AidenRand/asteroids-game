#include <SFML/Graphics.hpp>
#include <asteroid.hpp>
#include <bullet.hpp>
#include <vector>

Asteroid::Asteroid(float width, float height)
{
	// Load asteroid texture
	if (!texture1.loadFromFile("content/asteroid1.png"))
	{
		std::cout << "ERROR: Could not load large asteroid texture";
	}
	if (!texture2.loadFromFile("content/asteroid2.png"))
	{
		std::cout << "ERROR: Could not load large asteroid texture";
	}
	if (!texture3.loadFromFile("content/asteroid3.png"))
	{
		std::cout << "ERROR: Could not load large asteroid texture";
	}

	asteroid.setOrigin(64, 64);
	asteroid.setScale(width, height);

	// Generate random position and speed of asteroid
	int randomLargeX = (rand() % 12) - (rand() % 12);
	int randomLargeY = (rand() % 12) - (rand() % 12);
	randomAngle = rand() % 360;
	step = (rand() % 300) + 1;
	direction.x = -cos(randomAngle * (M_PI / 180));
	direction.y = sin(randomAngle * (M_PI / 180));
	velocity.x = direction.x * step;
	velocity.y = direction.y * step;

	asteroid.setPosition(sf::Vector2f(randomLargeX, randomLargeY));
}

void Asteroid::moveAsteroid(float dt)
{
	asteroid.move(velocity * dt);
}

void Asteroid::screenWrapping(int screenWidth, int screenHeight, float astRadius)
{
	// If player goes beyond x bounds set position to opposite site of screen
	if (asteroid.getPosition().x > screenWidth + astRadius)
	{
		asteroid.setPosition(0, asteroid.getPosition().y);
	}
	else if (asteroid.getPosition().x <= 0 - astRadius)
	{
		asteroid.setPosition(screenWidth, asteroid.getPosition().y);
	}

	// If player goes beyond y bounds set position to opposite site of screen
	if (asteroid.getPosition().y >= screenHeight + astRadius)
	{
		asteroid.setPosition(asteroid.getPosition().x, 0);
	}
	else if (asteroid.getPosition().y <= 0 - astRadius)
	{
		asteroid.setPosition(asteroid.getPosition().x, screenHeight);
	}
}

void Asteroid::bulletCollision(Bullet& bullet)
{
	auto bulletRect = bullet.bullet;

	if (asteroid.getGlobalBounds().intersects(bulletRect.getGlobalBounds()))
	{
		asteroid.setScale(0.5, 0.5);
		std::cout << "collision"
				  << "\n";
	}
}

void Asteroid::drawTo(sf::RenderWindow& window)
{
	window.draw(asteroid);
}

void Asteroid::chooseTexture()
{
	// Generate random number to set asteroid texture
	int randomTexture = rand() % 3;
	if (randomTexture == 1)
	{
		asteroid.setTexture(texture1);
	}
	else if (randomTexture == 2)
	{
		asteroid.setTexture(texture2);
	}
	else
	{
		asteroid.setTexture(texture3);
	}
}