#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
public:
	Player(float width, float height);
	void drawTo(sf::RenderWindow& window);
	void movePlayer(float dt);
	void screenWrapping(int& screen_width, int& screen_height);

private:
	sf::Texture normalTexture;
	sf::Texture firedTexture;
	sf::Sprite player;

	const float acc = 0.1f;
	const float dAcc = 1.0f;

	sf::Vector2f direction;
	sf::Vector2f acceleration;
	sf::Vector2f velocity;
	float x = 512;
	float y = 394;
};

#endif