#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class Button
{

public:

	Button(const sf::Vector2f& position,const sf::Vector2f& dimensions,const sf::Text& text);
	sf::Vector2f GetPosition() const { return framework.getPosition(); };
	sf::Vector2f GetSize() const { return framework.getSize(); };
	void Draw(sf::RenderWindow& window);



private:
	sf::RectangleShape framework;
	sf::Text text;

};

