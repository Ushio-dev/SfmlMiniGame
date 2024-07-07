#pragma once

#include <SFML/Graphics.hpp>

typedef struct {
	float x;
	float y;
}BallPosition;

class Ball
{
public:
	Ball(sf::RenderWindow* window);
	~Ball();
	void update(sf::FloatRect player);
	void draw(sf::RenderTarget* target);
	sf::Vector2f getPos();

private:
	sf::CircleShape ball;
	BallPosition position;
	sf::Vector2f velocity;
	
	void resetPosition();
	void collision(sf::FloatRect player);
};

