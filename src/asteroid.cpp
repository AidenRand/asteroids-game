#include <SFML/Graphics.hpp>
#include <asteroid.hpp>
#include <bullet.hpp>
#include <vector>

Asteroid::Asteroid(float width, float height)
{
	// Load asteroid texture
	if (!largeTexture.loadFromFile("content/asteroid.png"))
	{
		std::cout << "ERROR: Could not load large asteroid texture";
	}
	largeAsteroid.setTexture(largeTexture);

	largeAsteroid.setOrigin(64, 64);
	largeAsteroid.setScale(width, height);

	// Generate random position and speed of asteroid
	int randomLargeX = (rand() % 12) - (rand() % 12);
	int randomLargeY = (rand() % 12) - (rand() % 12);
	randomAngle = rand() % 360;
	step = (rand() % 300);
	direction.x = -cos(randomAngle * (M_PI / 180));
	direction.y = sin(randomAngle * (M_PI / 180));
	velocity.x = direction.x * step;
	velocity.y = direction.y * step;

	largeAsteroid.setPosition(sf::Vector2f(randomLargeX, randomLargeY));
}

void Asteroid::moveAsteroid(float dt)
{
	largeAsteroid.move(velocity * dt);
}

void Asteroid::screenWrapping(int screenWidth, int screenHeight, float astRadius)
{
	// If player goes beyond x bounds set position to opposite site of screen
	if (largeAsteroid.getPosition().x > screenWidth + astRadius)
	{
		largeAsteroid.setPosition(0, largeAsteroid.getPosition().y);
	}
	else if (largeAsteroid.getPosition().x <= 0 - astRadius)
	{
		largeAsteroid.setPosition(screenWidth, largeAsteroid.getPosition().y);
	}

	// If player goes beyond y bounds set position to opposite site of screen
	if (largeAsteroid.getPosition().y >= screenHeight + astRadius)
	{
		largeAsteroid.setPosition(largeAsteroid.getPosition().x, 0);
	}
	else if (largeAsteroid.getPosition().y <= 0 - astRadius)
	{
		largeAsteroid.setPosition(largeAsteroid.getPosition().x, screenHeight);
	}
}

void Asteroid::bulletCollision(Bullet& bullet)
{
	auto bulletRect = bullet.bullet;

	if (largeAsteroid.getGlobalBounds().intersects(bulletRect.getGlobalBounds()))
	{
		largeAsteroid.setScale(0.5, 0.5);
		std::cout << "collision"
				  << "\n";
	}
}

void Asteroid::drawTo(sf::RenderWindow& window)
{
	window.draw(largeAsteroid);
}