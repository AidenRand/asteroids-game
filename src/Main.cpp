#include <SFML/Graphics.hpp>
// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
#include <iostream>
#include <player.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Asteroids");
	window.setFramerateLimit(60);

	// Create delta time
	sf::Clock clock;
	float dt;

	Player player(1, 1, 512, 394);

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
		player.drawTo(window);
		window.display();
	}
}