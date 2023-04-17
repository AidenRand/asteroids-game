#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
public:
	Player(float width, float height, float x, float y);
	void drawTo(sf::RenderWindow& window);
	void movePlayer(float dt);
	void update();

private:
	sf::Texture normalTexture;
	sf::Texture firedTexture;
	sf::Sprite player;

	const float acc = 0.1f;
	const float dAcc = 1.0f;

	sf::Vector2f direction;
	sf::Vector2f acceleration;
	sf::Vector2f velocity;
};

#endif