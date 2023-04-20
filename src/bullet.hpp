#ifndef BULLET_HPP
#define BULLET_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(int width, int height);
	void setPos(sf::Vector2f newPos);
	void drawTo(sf::RenderWindow& window);
	void fireBullet(int speed, Player& player);
	void moveBullet();

private:
	sf::RectangleShape bullet;
	sf::Vector2f velocity;
};

#endif
