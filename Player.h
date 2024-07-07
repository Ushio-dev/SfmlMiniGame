#pragma once
#include <SFML/Graphics.hpp>
#include "Movement.h"

class Player
{
public:
	Player(sf::RenderWindow* window);
	~Player();

	void update(Movement direction);
	void draw(sf::RenderWindow* window);
	sf::FloatRect getPlayerBound();
private:
	sf::RectangleShape player;
};

