#include "Player.h"

Player::Player(sf::RenderWindow* window)
{
	player.setFillColor(sf::Color::White);
	player.setSize(sf::Vector2f(20.f, 100.f));
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	player.setPosition(30, window->getSize().y / 2.f);
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
			player.move(sf::Vector2f(0.f, -10.f));

		}
		//player.setPosition(player.getPosition().x, player.getPosition().y - 10.f);

		break;
	case DOWN:
		if (player.getPosition().y + player.getSize().y / 2 < 600) {
			player.move(sf::Vector2f(0.f, 10.f));

		}
		//player.move(sf::Vector2f(0.f, 10.f));
		//player.setPosition(player.getPosition().x, player.getPosition().y + 10.f);

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
