#include <SFML/Graphics.hpp>
#include <player.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Asteroids");
	window.setFramerateLimit(60);

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

		if (event.type == sf::Event::KeyPressed)
		{
			player.movePlayer(event.key.code, true);
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			player.movePlayer(event.key.code, true);
		}

		if (event.type == sf::Event::KeyReleased)
		{
			player.movePlayer(event.key.code, false);
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			player.movePlayer(event.key.code, false);
		}

		window.clear();
		player.drawTo(window);
		player.update();
		window.display();
	}
}