#ifndef BULLET_HPP
#define BULLET_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(float width, float height, float x, float y);
	void drawTo(sf::RenderWindow& window);
	void fireBullet(int speedX, int speedY, Player& player);

private:
	sf::RectangleShape bullet;
};

#endif