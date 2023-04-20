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
			Bullet bullet(2, 2, player.returnX(), player.returnY());
			bulletVec.push_back(bullet);
			isFiring = false;
		}

		for (long unsigned int i = 0; i < bulletVec.size(); i++)
		{
			bulletVec[i].fireBullet(10, 10, player);
			bulletVec[i].drawTo(window);
		}

		dt = clock.restart().asSeconds();

		player.movePlayer(dt);
		player.screenWrapping(screenWidth, screenHeight);
		player.drawTo(window);
		window.display();
	}
}