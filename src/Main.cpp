#include <SFML/Graphics.hpp>
#include <player.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Asteroids");
	window.setFramerateLimit(60);

	Player player(1.5, 1.5, 512, 394);

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

		window.clear();
		player.drawTo(window);
		window.display();
	}
}