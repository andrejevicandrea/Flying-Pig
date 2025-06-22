#pragma once
#include<SFML/Graphics.hpp>
#include <random>
#include "Collider.h"
#include "Player.h"
#include <iostream>
#define SPACEHEIGHT 200.0f
class Pipe
{
public:
	Pipe(const sf::Vector2f& sizeTop, const sf::Vector2f& sizeBottom, float speed, sf::Texture* pipeTopTexture, sf::Texture* pipeBottomTexture);
    sf::RectangleShape getBodyTop() { return bodyTop; }
	sf::RectangleShape getBodyBottom() { return bodyBottom; }
	float getSpeed() const { return speed; }
	Collider MakeCollider(sf::RectangleShape body) { return Collider(body); }
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void setBodyTopStartingPosition();
	void setBodyBottomStartingPosition(const sf::Vector2f& sizeBottom);
	static Pipe generatedPipe(float speed, sf::Texture* pipeTopTexture, sf::Texture* pipeBottomTexture);

private:
	sf::RectangleShape bodyTop;
	sf::RectangleShape bodyBottom;

	float speed;

};

