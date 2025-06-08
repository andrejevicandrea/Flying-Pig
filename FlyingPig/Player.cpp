#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	this->body.setSize(size);
	this->body.setPosition(position);
	this->body.setTexture(texture);

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(this->body);
}

void Player::Update(float deltaTime, unsigned int row)
{

	this->animation.Update(row, deltaTime);
	this->body.setTextureRect(animation.uvRect);
}
