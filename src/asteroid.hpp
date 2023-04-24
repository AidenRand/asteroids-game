#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SFML/Graphics.hpp>
#include <bullet.hpp>
#include <cstdlib>
#include <ctime>
#include <random>

class Asteroid
{
public:
	Asteroid(float width, float weight);
	void moveAsteroid();
	void screenWrapping(int screenWidth, int screenHeight, float astRadius);
	void bulletCollision(Bullet& bullet);
	void drawTo(sf::RenderWindow& window);
	sf::Vector2f chooseDir();

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