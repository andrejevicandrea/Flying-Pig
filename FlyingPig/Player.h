#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#define GRAVITY 981.0f
class Player
{

public:

	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position, float maxJump);
	void Draw(sf::RenderWindow& window);
	float GetVelocity() { return velocity; }
	void SetStartVelocity() { this->velocity = velocityStart; }
	void Update(float deltaTime, unsigned int row, bool gameStarted);
	Collider makeCollider() { return Collider(this->body); }
	


private:
	sf::RectangleShape body;
	Animation animation;

	float velocityStart;
	float velocity;
	float maxJump;

};

