#include "Player.h"
#include <iostream>


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position, float maxJump) :
	animation(texture, imageCount, switchTime)
{
	
	this->velocity = 0.0f;
	this->maxJump = maxJump;
	this->body.setSize(size);
	this->body.setPosition(position);
	this->body.setTexture(texture);
	this->velocityStart = -sqrt(2 * GRAVITY * maxJump);

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(this->body);
}

void Player::Update(float deltaTime, unsigned int row, bool gameStarted)
{

	if (gameStarted) {
		float s = 0.0f;

		s = velocity * deltaTime - GRAVITY * deltaTime * deltaTime / 2;
		velocity += GRAVITY * deltaTime;
		this->body.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y + s));

	}

	this->animation.Update(row, deltaTime);
	this->body.setTextureRect(animation.uvRect);

}

void Player::SetStartingPosition()
{
	sf::Vector2f startingPosition(100.0f, 300.0f - 50.0f);
	body.setPosition(startingPosition);
}
