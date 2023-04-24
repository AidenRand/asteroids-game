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

	largeAsteroid.setPosition(randomLargeX, randomLargeY);
}

void Asteroid::moveAsteroid()
{

	largeAsteroid.move(velocity);
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
	}
}

sf::Vector2f Asteroid::chooseDir()
{
	std::srand((int)std::time(NULL));

	randomLargeX = (rand() % 800) + 1;
	randomLargeY = (rand() % 600) + 1;
	randomAngle = rand() % 360;
	step = (rand() % 10) + (-3);
	direction.x = -cos(randomAngle * (M_PI / 180));
	direction.y = sin(randomAngle * (M_PI / 180));
	velocity.x = direction.x * step;
	velocity.y = direction.y * step;

	return velocity;
}

void Asteroid::drawTo(sf::RenderWindow& window)
{
	window.draw(largeAsteroid);
}