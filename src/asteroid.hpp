#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <random>

class Asteroid
{
public:
	Asteroid(float width, float weight);
	void moveAsteroids();
	void drawLarge(sf::RenderWindow& window);

private:
	sf::Texture largeTexture;
	sf::Sprite largeAsteroid;

	int step;

	int randomLargeX;
	int randomLargeY;

	int randomAngle;
	sf::Vector2f direction;
	sf::Vector2f velocity;
};

#endif