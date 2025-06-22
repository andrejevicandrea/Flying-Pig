#include "Pipe.h"


Pipe::Pipe(const sf::Vector2f& sizeTop, const sf::Vector2f& sizeBottom,float speed, sf::Texture* pipeTopTexture, sf::Texture* pipeBottomTexture)
{
 	this->bodyTop.setSize(sizeTop);
	this->bodyBottom.setSize(sizeBottom);
	this->bodyTop.setPosition(sf::Vector2f(800.0f, 0.0f));
	this->bodyBottom.setPosition(sf::Vector2f(800.0f,600.0f - sizeBottom.y));
	this->speed = speed;
	this->bodyTop.setTexture(pipeTopTexture);
	this->bodyBottom.setTexture(pipeBottomTexture);
	this->bodyTop.setTextureRect(sf::IntRect(sf::Vector2i(0, pipeTopTexture->getSize().y - sizeTop.y), sf::Vector2i(int(sizeTop.x), int(sizeTop.y))));
	this->bodyBottom.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(int(sizeBottom.x), int(sizeBottom.y))));

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


Pipe Pipe::generatedPipe(float speed, sf::Texture* pipeTopTexture, sf::Texture* pipeBottomTexture)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> height(100.0f, 300.0f);
	float random = height(gen);

	float tmp = 600.0f - SPACEHEIGHT - random;

	Pipe newPipe(sf::Vector2f(100.0f, random), sf::Vector2f(100.0f, tmp), speed, pipeTopTexture, pipeBottomTexture);
	return newPipe;
}

