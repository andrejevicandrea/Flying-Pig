#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Pipe.h"
#include "Collider.h"
#include <deque>
#include <iostream>
#include <random>
																																																																				
class Game
{
public:
	Game(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position, float maxJump,
		const sf::Vector2f& sizeTop, const sf::Vector2f& sizeBottom, float speed, sf::Texture* pipeTopTexture, sf::Texture* pipeBottomTexture,
		bool endGame);
	void Update(sf::RenderWindow& window, float deltaTime, unsigned int row, bool gameStarted);
	void SetPlayerVelocity(){ player.SetStartVelocity(); }
	bool getEndGame() { return endGame; }
	void setEndGame(bool endGame){ this->endGame = endGame; }
	void RestartGame(sf::RenderWindow& window, float deltaTime, unsigned int row, bool gameStarted);

private:
	Player player;
	std::deque<Pipe> pipes;
	sf::Texture* pipeTopTexture;
	sf::Texture* pipeBottomTexture;

	bool endGame;

};

