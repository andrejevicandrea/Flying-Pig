#include "Pipe.h"

Pipe::Pipe(const sf::Vector2f& sizeTop, const sf::Vector2f& sizeBottom,float speed)
{
 	this->bodyTop.setSize(sizeTop);
	this->bodyBottom.setSize(sizeBottom);
	this->bodyTop.setPosition(sf::Vector2f(800.0f, 0.0f));
	this->bodyBottom.setPosition(sf::Vector2f(800.0f,600.0f - sizeBottom.y));
	this->speed = speed;
}

void Pipe::Update(float deltaTime)
{
	
	float s = 0.0f;

	s += deltaTime * speed;

	bodyTop.move(sf::Vector2f(-s, 0.0f));
	bodyBottom.move(sf::Vector2f(-s, 0.0f));

}

void Pipe::Draw(sf::RenderWindow& window)
{
	window.draw(bodyTop);
	window.draw(bodyBottom);
}

void Pipe::setBodyTopStartingPosition()
{
	bodyTop.setPosition(sf::Vector2f(800.0f, 0.0f));
}

void Pipe::setBodyBottomStartingPosition(const sf::Vector2f& sizeBottom)
{
	
	bodyBottom.setPosition(sf::Vector2f(800.0f, 600.0f - sizeBottom.y));
}

