#include "Ball.h"

Ball::Ball(sf::RenderWindow* window)
{
	this->ball = sf::CircleShape(10.f);
	ball.setFillColor(sf::Color::White);
	ball.setOrigin(ball.getRadius(), ball.getRadius());
	ball.setPosition(window->getSize().x / 2, window->getSize().y / 2);

	velocity = sf::Vector2f(-5.f, -5.f);

	point = 0;
}

Ball::~Ball()
{
}

void Ball::update(sf::FloatRect playerOne, sf::FloatRect playerTwo, GameState state)
{
	if (state == GameState::PLAYING) {
		ball.move(velocity);
		// Rebotar en los bordes de la ventana
		sf::Vector2f position = ball.getPosition();
		isPoint();
		if (position.x <= 0 || position.x >= 800 - ball.getRadius() * 2)
			//velocity.x = -velocity.x;
			resetPosition();

		
		if (position.y <= 0 || position.y >= 600 - ball.getRadius() * 2)
			velocity.y = -velocity.y;

		if (ball.getGlobalBounds().intersects(playerOne))
		{
			velocity.x = -velocity.x;
			velocity += sf::Vector2f(0.1f, 0.1f);
		}
		if (ball.getGlobalBounds().intersects(playerTwo))
		{
			velocity.x = -velocity.x;
			velocity += sf::Vector2f(-1.f, -1.f);
		}

	}

	if (state == GameState::PAUSED) {
		ball.move(sf::Vector2f(0.f,0.f));
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

void Ball::isPoint()
{
	// debo verificar a quien darle el punto
	sf::Vector2f position = ball.getPosition();
	if (position.x <= 0) {
		point = 2;
	}

	if (position.x >= 800 - ball.getRadius() * 2) {
		point = 1;
	}
}

int Ball::getPoint() const
{
	return point;
}

void Ball::resetPoint()
{
	point = 0;
}

void Ball::resetPosition()
{
	ball.setPosition(sf::Vector2f(400.f, 300.f));
	velocity = sf::Vector2f(-5.f, -5.f);
}

void Ball::collision(sf::FloatRect player)
{
	if (ball.getGlobalBounds().intersects(player));
}
