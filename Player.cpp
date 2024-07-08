#include "Player.h"

Player::Player(sf::RenderWindow* window, int numberPlayer)
{
	player.setFillColor(sf::Color::White);
	player.setSize(sf::Vector2f(20.f, 100.f));
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	if (numberPlayer == 1) {
		player.setPosition(15, window->getSize().y / 2.f);
	}
	if (numberPlayer == 2) {
		player.setPosition(window->getSize().x - 15, window->getSize().y / 2.f);

	}
	score = 0;
}

Player::~Player()
{

}

void Player::update(Movement direction)
{
	switch (direction)
	{
	case UP:
		if (player.getPosition().y - player.getSize().y / 2 > 0) {
			player.move(sf::Vector2f(0.f, -5.f));

		}
		break;
	case DOWN:
		if (player.getPosition().y + player.getSize().y / 2 < 600) {
			player.move(sf::Vector2f(0.f, 5.f));
		}
		break;
	default:
		break;
	}
}

void Player::draw(sf::RenderWindow* window)
{
	window->draw(player);
}

sf::FloatRect Player::getPlayerBound()
{
	return player.getGlobalBounds();
}

void Player::addScore()
{
	score += 1;
}

