#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
public:
	Player(float width, float height, float x, float y);
	void drawTo(sf::RenderWindow& window);
	void update();

private:
	sf::Texture texture;
	sf::Sprite player;
};

#endif