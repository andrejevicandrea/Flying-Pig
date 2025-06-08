#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
class Player
{

public:

	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position);
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime, unsigned int row);


private:
	sf::RectangleShape body;
	Animation animation;

};

