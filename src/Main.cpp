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
	std::srand(time(NULL));
	// Create delta time
	sf::Clock clock;
	float dt;

	Bullet bullet(2, 2);
	std::vector<Bullet> bulletVec;
	bool isFiring = false;
	unsigned int reloadTimer = 0;

	Player player(1, 1);
	long unsigned int maxAsteroids = 5;

	std::vector<Asteroid> asteroidVec;

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
		window.clear(sf::Color(5, 5, 5));

		// If isFiring is true, fire the bullet
		dt = clock.restart().asSeconds();
		if (reloadTimer == 0)
		{
			if (isFiring)
			{
				bullet.fireBullet(550, player, dt);
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
		for (long unsigned int i = 0; i < bulletVec.size(); ++i)
		{
			asteroidVec[i].bulletCollision(bulletVec[i]);
			bulletVec[i].moveBullet(dt);
			bulletVec[i].drawTo(window);

			// Despawn bullets when they go beyond screen
			if (bulletVec[i].returnPosX() < 0 || bulletVec[i].returnPosX() > screenWidth
				|| bulletVec[i].returnPosY() < 0 || bulletVec[i].returnPosY() > screenHeight)
			{
				bulletVec.erase(bulletVec.begin() + i);
			}
		}

		Asteroid asteroids(1, 1);

		if (asteroidVec.size() < maxAsteroids)
		{
			asteroidVec.push_back(asteroids);
		}

		for (long unsigned int i = 0; i != asteroidVec.size(); i++)
		{
			asteroidVec[i].moveAsteroid(dt);
			asteroidVec[i].screenWrapping(screenWidth, screenHeight, 64);
			asteroidVec[i].drawTo(window);
		}

		player.movePlayer(dt);
		player.screenWrapping(screenWidth, screenHeight);
		player.drawTo(window);
		window.display();
	}
}