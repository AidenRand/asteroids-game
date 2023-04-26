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
	void moveAsteroid(float dt);
	void screenWrapping(int screenWidth, int screenHeight, float astRadius);
	void bulletCollision(Bullet& bullet);
	void drawTo(sf::RenderWindow& window);

private:
	sf::Texture largeTexture;
	sf::Sprite largeAsteroid;

	sf::Vector2f direction;
	sf::Vector2f velocity;

	int randomLargeX;
	int randomLargeY;
	int randomAngle;
	int step;
};

#endif