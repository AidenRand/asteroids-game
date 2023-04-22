#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SFML/Graphics.hpp>
#include <random>

class Asteroid
{
public:
	Asteroid(float smallWidth, float smallHeight);
	void moveAsteroids();
	void drawAsteroids(sf::RenderWindow& window);

private:
	sf::Sprite smallAsteroid;
	sf::Texture smallTexture;

	sf::Texture mediumTexture;
	sf::Sprite mediumAsteroid;

	sf::Texture largeTexture;
	sf::Sprite largeAsteroid;

	int randomX = (rand() % 1000);
	int randomY = (rand() % 800);

	int stepX = 5 + (rand() % 7);
	int stepY = 5 + (rand() % 7);
};

#endif