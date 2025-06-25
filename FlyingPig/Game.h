#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Pipe.h"
#include "Collider.h"
#include <deque>
#include <iostream>
#include <random>
#include "Button.h"
#define ADDEDSCORE true
																																																																				
class Game
{
public:
	Game(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position, float maxJump,
		const sf::Vector2f& sizeTop, const sf::Vector2f& sizeBottom, float speed, sf::Texture* pipeTopTexture, sf::Texture* pipeBottomTexture,
		bool endGame
		,const sf::Vector2f& positionButton, const sf::Vector2f& dimensions, const sf::Text& text, sf::Texture* textureButton);
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
	Button scoreButton;

	int score;
	int highScore;
	bool addedScore;
	bool endGame;

};

