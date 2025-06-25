#include "Game.h"

Game::Game(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position, float maxJump,
	const sf::Vector2f& sizeTop, const sf::Vector2f& sizeBottom, float speed, sf::Texture* pipeTopTexture, sf::Texture* pipeBottomTexture,
	bool endGame
	,const sf::Vector2f& positionButton, const sf::Vector2f& dimensions, const sf::Text& text, sf::Texture* textureButton) :
	player(texture, imageCount, switchTime, size, position, maxJump)
	, scoreButton(positionButton, dimensions, text, textureButton)
	
{   
	this->endGame = endGame;
	this->pipeTopTexture = pipeTopTexture;
	this->pipeBottomTexture = pipeBottomTexture;
	pipes.push_back(Pipe(sizeTop, sizeBottom, speed, pipeTopTexture, pipeBottomTexture));
	score = 0;
	addedScore = true;
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

	if (pipe.getBodyTop().getPosition().x + 100.0f < player.getBody().getPosition().x) {
		if (addedScore) {
			score++;
			addedScore = false;
		}
			
		scoreButton.SetText("Score: " + std::to_string(score));
	}

 	if (pipe.getBodyTop().getPosition().x  < -100.0f) {
		pipes.pop_front();
		addedScore = true;
	}

	if (pipes.back().getBodyTop().getPosition().x < 400.0f) {
		
		float speed = pipes.front().getSpeed();
		Pipe newPipe = Pipe:: generatedPipe(speed, pipeTopTexture, pipeBottomTexture);
		pipes.push_back(newPipe);
		
	}

	player.Update(deltaTime, row, gameStarted);
	player.Draw(window);

	for (Pipe& p : pipes) {
		p.Update(deltaTime);
		p.Draw(window);
	}

	scoreButton.Draw(window);

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
	
