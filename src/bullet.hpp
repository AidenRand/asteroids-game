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
	void fireBullet(int speed, Player& player, float& dt);
	void moveBullet(float dt);
	int returnPosX();
	int returnPosY();

private:
	sf::RectangleShape bullet;
	sf::Vector2f velocity;
};

#endif
