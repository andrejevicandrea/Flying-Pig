#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Collider
{
public:
	Collider(sf::RectangleShape body);

	std::vector<sf::Vector2f> GetPoints();

	bool checkCollision( Collider& other);
	float GetArea(const sf::Vector2f& A, const sf::Vector2f& B, const sf:: Vector2f& C);
	bool pointIn(const sf::Vector2f& point, const std::vector<sf::Vector2f>& polygon, const float polygonArea);
	



private:
	sf::RectangleShape body;

	
};

