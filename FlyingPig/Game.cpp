#include "Game.h"

Game::Game(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position, float maxJump, 
	const sf::Vector2f& sizeTop, const sf::Vector2f& sizeBottom, float speed, bool endGame) : 
	player(texture, imageCount, switchTime, size, position, maxJump)
{
	this->endGame = endGame;
	pipes.push_back(Pipe(sizeTop, sizeBottom, speed));
}

void Game::Update(sf::RenderWindow& window,float deltaTime, unsigned int row, bool gameStarted)
{
	Collider playerCollider = player.makeCollider();
	Pipe pipe = pipes.front();
	Collider pipeTopCollider = pipe.MakeCollider(pipe.getBodyTop());
	Collider pipeBottomCollider = pipe.MakeCollider(pipe.getBodyBottom());

	if (!gameStarted) {
		player.Update(deltaTime, row, gameStarted);
		player.Draw(window);
		
		return;
	}
	if ((playerCollider.checkCollision(pipeTopCollider)) || (playerCollider.checkCollision(pipeBottomCollider))) {
		endGame = true;
		return;
	}
 	if (pipe.getBodyTop().getPosition().x  < -100.0f) {
		pipes.pop_front();
	}

	if (pipes.back().getBodyTop().getPosition().x < 400.0f) {
		std::random_device rd; 
		std::mt19937 gen(rd()); 
		std::uniform_real_distribution<float> height(100.0f, 300.0f);
		float random = height(gen);

		float tmp = 600.0f - SPACEHEIGHT - random;

		Pipe newPipe(sf::Vector2f(100.0f, random), sf::Vector2f(100.0f, tmp), pipe.getSpeed());
		pipes.push_back(newPipe);

		
		
	}

	player.Update(deltaTime, row, gameStarted);
	player.Draw(window);

	for (Pipe& p : pipes) {
		p.Update(deltaTime);
		p.Draw(window);
	}

	return;
	
		
}

void Game::RestartGame(sf::RenderWindow& window, float deltaTime, unsigned int row, bool gameStarted)

{	
	

	for (int i = 0; i < pipes.size() - 1; i++) {
		pipes.pop_front();
	}

	pipes.front().setBodyTopStartingPosition();
	pipes.front().setBodyBottomStartingPosition(pipes.front().getBodyBottom().getSize());

	if (!gameStarted) {
		player.SetStartingPosition();
		player.Update(deltaTime, row, gameStarted);
		player.Draw(window);

		return;
	}

	


}
	
