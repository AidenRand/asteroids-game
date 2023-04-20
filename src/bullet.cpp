#include "bullet.hpp"
#include "player.hpp"

Bullet::Bullet(float width, float height, float x, float y)
{
	bullet.setSize(sf::Vector2f(width, height));
	bullet.setOrigin(width / 2, height / 2);
	bullet.setFillColor(sf::Color(200, 200, 200));
	bullet.setPosition(x, y);
}

void Bullet::drawTo(sf::RenderWindow& window)
{
	window.draw(bullet);
}

void Bullet::fireBullet(int speedX, int speedY, Player& player)
{
	auto playerDirX = player.player.getRotation() * M_PI / 180;
	auto playerDirY = player.player.getRotation() * M_PI / 180;
	auto velocityX = speedX * cos(playerDirX);
	auto velocityY = speedY * sin(playerDirY);

	bullet.move(velocityX, velocityY);
}