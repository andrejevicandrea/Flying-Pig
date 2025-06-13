#pragma once
#include<SFML/Graphics.hpp>
#include <random>
#include "Collider.h"
#include "Player.h"
#define SPACEHEIGHT 200.0f
class Pipe
{
public:
	Pipe(const sf::Vector2f& sizeTop, const sf::Vector2f& sizeBottom, float speed);
	Collider MakeCollider(sf::RectangleShape body) { return Collider(body); }
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape bodyTop;
	sf::RectangleShape bodyBottom;

	float speed;

};

