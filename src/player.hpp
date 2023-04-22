#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(float width, float height);
	void drawTo(sf::RenderWindow& window);
	void movePlayer(float dt);
	void screenWrapping(int& screen_width, int& screen_height);
	int returnX();
	int returnY();
	int returnAngle();

	sf::Vector2f direction;
	sf::Sprite player;

private:
	sf::Texture normalTexture;
	sf::Texture firedTexture;
	int switchTexture = 0;

	const float acc = 1.0f;
	const float dAcc = 1.0f;

	sf::Vector2f acceleration;
	sf::Vector2f velocity;
	float x = 512;
	float y = 394;
};

#endif
