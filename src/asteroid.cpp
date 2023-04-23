#include <SFML/Graphics.hpp>
#include <asteroid.hpp>

Asteroid::Asteroid(float width, float height)
{
	if (!largeTexture.loadFromFile("content/largeAsteroid.png"))
	{
		std::cout << "ERROR: Could not load large asteroid texture";
	}
	largeAsteroid.setTexture(largeTexture);

	largeAsteroid.setOrigin(64, 64);
	largeAsteroid.setScale(width, height);

	std::srand((int)std::time(NULL));

	randomLargeX = (rand() % 800) + 1;
	randomLargeY = (rand() % 600) + 1;
	randomAngle = rand() % 360;
	step = (rand() % 15) + (-3);
	direction.x = -cos(randomAngle * (M_PI / 180));
	direction.y = sin(randomAngle * (M_PI / 180));

	largeAsteroid.setPosition(randomLargeX, randomLargeY);
}

void Asteroid::moveAsteroid()
{

	velocity.x = direction.x * step;
	velocity.y = direction.y * step;
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

void Asteroid::drawTo(sf::RenderWindow& window)
{
	window.draw(largeAsteroid);
}