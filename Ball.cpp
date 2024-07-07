#include "Ball.h"

Ball::Ball(sf::RenderWindow* window)
{
	this->ball = sf::CircleShape(10.f);
	ball.setFillColor(sf::Color::White);
	ball.setOrigin(ball.getRadius() / 2, ball.getRadius() / 2);
	ball.setPosition(window->getSize().x / 2, window->getSize().y / 2);

	velocity = sf::Vector2f(-3.f, -3.f);
}

Ball::~Ball()
{
}

void Ball::update(sf::FloatRect player)
{
	ball.move(velocity);
	// Rebotar en los bordes de la ventana
	sf::Vector2f position = ball.getPosition();
	if (position.x <= 0 || position.x >= 800 - ball.getRadius() * 2)
		velocity.x = -velocity.x;
	if (position.y <= 0 || position.y >= 600 - ball.getRadius() * 2)
		velocity.y = -velocity.y;

	if (ball.getGlobalBounds().intersects(player))
	{
		velocity.x = -velocity.x;
		velocity += sf::Vector2f(0.5f, 0.5f);
	}
}

void Ball::draw(sf::RenderTarget* window)
{
	window->draw(ball);
}

sf::Vector2f Ball::getPos()
{
	return ball.getPosition();
}

void Ball::resetPosition()
{
	ball.setPosition(sf::Vector2f(400.f, 300.f));
}

void Ball::collision(sf::FloatRect player)
{
	if (ball.getGlobalBounds().intersects(player));
}
