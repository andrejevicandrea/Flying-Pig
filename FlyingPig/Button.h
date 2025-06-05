#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class Button
{

public:


	Button() = default;
	Button(const sf::Vector2f& position, const sf::Vector2f& dimensions, const sf::Text& text);
	void CenterText();
	sf::Vector2f GetPosition() const { return framework.getPosition(); }
	sf::Vector2f GetSize() const { return framework.getSize(); }
	std::string GetText() { return text.getString(); }
	void SetText(const std::string& newText) { this->text.setString(newText); }
	void SetPosition(const sf::Vector2f position) { this->framework.setPosition(position); }
	void Draw(sf::RenderWindow& window);



private:
	sf::RectangleShape framework;
	sf::Text text;

};

