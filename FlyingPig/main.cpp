#include <SFML/Graphics.hpp>
#include "Button.h"

bool checkButton(const Button& button,const sf::Vector2i& localPosition) {
    sf::Vector2f position = button.GetPosition();
    sf::Vector2f size = button.GetSize();

    if (localPosition.x <= position.x + size.x && localPosition.x >= position.x && localPosition.y <= position.y + size.y && localPosition.y >= position.y) {
        return true;
    }
    return false;
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800,600)), "Flying Pig", sf::Style::Resize | sf::Style::Close, sf::State::Windowed);
    window.setPosition(sf::Vector2i(600+1920, 400));
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Font font;
    if (!font.openFromFile("Anton-Regular.ttf")) {
        return -1;
    }
    sf::Text text(font, "Start");
    Button startButton(sf::Vector2f(300.0f,250.0f),sf::Vector2f (200,100),text);
    text.setString("Settings");
    Button settingsButton(sf::Vector2f(300.0f, 351.0f), sf::Vector2f(200, 100), text);
    text.setString("Exit");
    Button exitButton(sf::Vector2f(300.0f, 452.0f), sf::Vector2f(200, 100), text);
    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::MouseButtonPressed>() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);

                if (checkButton(startButton, localPosition)) {
                    std::cout << 1;
                }
                else {
                    std::cout << 0;
                }
            }
        }

        window.clear();
        startButton.Draw(window);
        settingsButton.Draw(window);
        exitButton.Draw(window);
        window.display();
    }
}