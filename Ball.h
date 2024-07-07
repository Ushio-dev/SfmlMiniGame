#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Player.h"

typedef struct {
	float x;
	float y;
}BallPosition;

class Ball
{
public:
	Ball(sf::RenderWindow* window);
	~Ball();
	void update(sf::FloatRect playerOne, sf::FloatRect playerTwo, GameState state);
	void draw(sf::RenderTarget* target);
	sf::Vector2f getPos();
	bool isPoint(Player* player);

private:
	sf::CircleShape ball;
	BallPosition position;
	sf::Vector2f velocity;
	
	void resetPosition();
	void collision(sf::FloatRect player);
};

