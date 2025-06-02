#include "Button.h"


Button::Button(const sf::Vector2f& position, const sf::Vector2f& dimensions,const sf::Text& text) : text(text)
{
	this->framework.setPosition(position);
	this->framework.setSize(dimensions);
	this->text.setFillColor(sf::Color::Black);
	sf::FloatRect textBounds = this->text.getLocalBounds();
	this->text.setOrigin(textBounds.getCenter());

	this->text.setPosition(position + dimensions / 2.0f);
	
	
}

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(this->framework);
	window.draw(this->text);

}
