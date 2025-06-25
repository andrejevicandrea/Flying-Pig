#include "Button.h"


Button::Button(const sf::Vector2f& position, const sf::Vector2f& dimensions,const sf::Text& text,sf::Texture* texture) : text(text)
{
	this->framework.setPosition(position);
	this->framework.setSize(dimensions);
	this->text.setFillColor(sf::Color::White);
	this->framework.setTexture(texture);
	CenterText();
	
	
}

void Button::CenterText()
{
	sf::Vector2f position = this->GetPosition();
	sf::Vector2f dimensions = this->GetSize();
	this->text.setPosition(position + dimensions / 2.0f);

	sf::FloatRect textBounds = this->text.getLocalBounds();
	this->text.setOrigin(textBounds.getCenter());

}

void Button::Draw(sf::RenderWindow& window)
{
	window.draw(this->framework);
	window.draw(this->text);

}
