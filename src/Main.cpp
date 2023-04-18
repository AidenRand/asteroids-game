#include <SFML/Graphics.hpp>
// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
#include <iostream>
#include <player.hpp>

int main()
{
	int screenWidth = 1000;
	int screenHeight = 800;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Asteroids");
	window.setFramerateLimit(60);

	// Create delta time
	sf::Clock clock;
	float dt;

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
		}

		dt = clock.restart().asSeconds();

		window.clear();
		player.movePlayer(dt);
		player.screenWrapping(screenWidth, screenHeight);
		player.drawTo(window);
		window.display();
	}
}