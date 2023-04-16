#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
public:
	Player(float width, float height, float x, float y);
	void drawTo(sf::RenderWindow& window);
	void movePlayer();
	void update();

private:
	sf::Texture texture;
	sf::Sprite player;

	bool rotateLeft = false;
	bool rotateRight = false;
	bool moveForward = false;
	float stepy = 0;
	float stepx = 0;

	sf::Vector2f acceleration;
	sf::Vector2f velocity;
};

#endif