#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	this->totalTime = 0.0f;
	this->currentImage.x = 0; // column 

	sf::Vector2u textureSize = texture->getSize();
	this->uvRect.size.x = textureSize.x / (float) imageCount.x;
	this->uvRect.size.y = textureSize.y / (float)imageCount.y;
}

void Animation::Update(int row, float deltatime)
{
	currentImage.y = row;
	totalTime += deltatime;

	if (totalTime >= switchTime) {
		totalTime = 0.0f;
		currentImage.x++;
		if (currentImage.x == imageCount.x) {
			currentImage.x = 0;
		}
	}

	//move top-left  uvRect
	uvRect.position.y = currentImage.y * (int) uvRect.size.y;
	uvRect.position.x = currentImage.x * (int)uvRect.size.x;
	
}
