#pragma once
#include <SFML/Graphics.hpp>
#include "Movement.h"

class Player
{
public:
	Player(sf::RenderWindow* window, int numberPlayer);
	~Player();

	void update(Movement direction);
	void draw(sf::RenderWindow* window);
	sf::FloatRect getPlayerBound();

	void addScore();

	int getScore() const;
private:
	sf::RectangleShape player;
	int score;
};

