#include <SFML/Graphics.hpp>
#include <asteroid.hpp>
#include <bullet.hpp>
#include <iostream>
#include <player.hpp>
#include <vector>

int main()
{
	int screenWidth = 1000;
	int screenHeight = 800;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Asteroids");
	window.setFramerateLimit(60);
	// Create delta time
	sf::Clock clock;
	float dt;

	Bullet bullet(2, 2);
	std::vector<Bullet> bulletVec;
	bool isFiring = false;
	unsigned int reloadTimer = 0;

	Player player(1, 1);

	Asteroid asteroids(1, 1);

	// std::vector<Asteroid> asteroidVec;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				isFiring = true;
				reloadTimer++;
			}
		}

		window.clear();
		// If isFiring is true, fire the bullet

		dt = clock.restart().asSeconds();
		if (reloadTimer == 0)
		{
			if (isFiring)
			{
				bullet.fireBullet(550, player, dt);
				Asteroid asteroids(1, 1);
				bullet.setPos(sf::Vector2f(player.returnX(), player.returnY()));
				bulletVec.push_back(bullet);
				isFiring = false;
			}
		}
		else
		{
			reloadTimer--;
		}

		// Continue moving bullet in original direction
		for (long unsigned int i = 0; i < bulletVec.size(); i++)
		{
			bulletVec[i].moveBullet(dt);
			bulletVec[i].drawTo(window);
			// asteroidVec[i].moveAsteroids();
			// asteroidVec[i].drawAsteroids(window);

			// Despawn bullets when they go beyond screen
			if (bulletVec[i].returnPosX() < 0 || bulletVec[i].returnPosX() > screenWidth
				|| bulletVec[i].returnPosY() < 0 || bulletVec[i].returnPosY() > screenHeight)
			{
				bulletVec.erase(bulletVec.begin() + i);
			}
		}

		asteroids.moveAsteroid();
		asteroids.screenWrapping(screenWidth, screenHeight, 50);
		asteroids.drawTo(window);
		player.movePlayer(dt);
		player.screenWrapping(screenWidth, screenHeight);
		player.drawTo(window);
		window.display();
	}
}