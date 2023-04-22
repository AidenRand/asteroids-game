#include <SFML/Graphics.hpp>
#include <asteroid.hpp>

Asteroid::Asteroid(float smallWidth, float smallHeight)
{
	if (!smallTexture.loadFromFile("content/smallAsteroid.png"))
	{
		std::cout << "ERROR: Could not load small asteroid texture";
	}

	// if (!mediumTexture.loadFromFile("content/mediumAsteroid.png"))
	// {
	// 	std::cout << "ERROR: Could not load medium asteroid texture";
	// }

	// if (!largeTexture.loadFromFile("content/largeAsteroid.png"))
	// {
	// 	std::cout << "ERROR: Could not load large asteroid texture";
	// }

	smallAsteroid.setScale(smallWidth, smallHeight);
	smallAsteroid.setTexture(smallTexture);
	// mediumAsteroid.setTexture(mediumTexture);
	// largeAsteroid.setTexture(largeTexture);

	smallAsteroid.setOrigin(16, 16);
	// mediumAsteroid.setOrigin(32, 32);
	// largeAsteroid.setOrigin(64, 64);
	smallAsteroid.setPosition(randomX, randomY);
	// mediumAsteroid.setPosition(randomX, randomY);
	// largeAsteroid.setPosition(randomX, randomY);
}

void Asteroid::moveAsteroids()
{
	smallAsteroid.move(stepX, stepY);
	// mediumAsteroid.move(stepX, stepY);
	// largeAsteroid.move(stepX, stepY);
}

void Asteroid::drawAsteroids(sf::RenderWindow& window)
{
	window.draw(smallAsteroid);
	// window.draw(mediumAsteroid);
	// window.draw(largeAsteroid);
}