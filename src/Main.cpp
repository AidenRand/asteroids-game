#include <SFML/Graphics.hpp>
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

	Bullet bullet(10, 10);

	std::vector<Bullet> bulletVec;
	bool isFiring = false;

	Player player(1, 1);

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
			}
		}

		window.clear();
		if (isFiring)
		{
			bullet.fireBullet(10, player);
			bullet.setPos(sf::Vector2f(player.returnX(), player.returnY()));
			bulletVec.push_back(bullet);
			isFiring = false;
		}

		for (auto& bullet : bulletVec)
		{
			bullet.moveBullet();
			bullet.drawTo(window);
		}

		dt = clock.restart().asSeconds();

		player.movePlayer(dt);
		player.screenWrapping(screenWidth, screenHeight);
		player.drawTo(window);
		window.display();
	}
}