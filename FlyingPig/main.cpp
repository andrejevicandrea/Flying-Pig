#include <SFML/Graphics.hpp>
#include "Button.h"
#include <vector>

enum WindowNames {
    Menu = 0, //show start, settings and exit buttons
    Start, //game is running
    Settings, //show music checkBox, volume and back to menu button
    Exit //show message "Are yoou sure?" and two buttons Yes/No
};

WindowNames windowName = Menu;

bool checkButton(const Button& button,const sf::Vector2i& localPosition) {
    sf::Vector2f position = button.GetPosition();
    sf::Vector2f size = button.GetSize();

    if (localPosition.x <= position.x + size.x && localPosition.x >= position.x && localPosition.y <= position.y + size.y && localPosition.y >= position.y) {
        return true;
    }
    return false;
}
void start(const sf::RenderWindow& window) {

}

void menu(const sf::Vector2i& localPosition,const std::vector<Button>& buttons) {

    for (Button button : buttons) {
        if (checkButton(button, localPosition)) {
            std::string buttonName = button.GetText();
            if (buttonName == "Start") {
                windowName = Start;
                //std::cout << "Start\n";
            }
            if (buttonName == "Settings") {
                windowName = Settings;
                //std::cout << "Settings\n";
            }
            if (buttonName == "Exit") {
                windowName = Exit;
                //std::cout << "Exit\n";
            }
        }
    }

}

std::vector<Button> setUpMenu(const sf::Font& font) {
    sf::Text text(font, "Start");
    Button startButton(sf::Vector2f(300.0f, 250.0f), sf::Vector2f(200, 100), text);
    text.setString("Settings");
    Button settingsButton(sf::Vector2f(300.0f, 351.0f), sf::Vector2f(200, 100), text);
    text.setString("Exit");
    Button exitButton(sf::Vector2f(300.0f, 452.0f), sf::Vector2f(200, 100), text);
    std::vector<Button> buttons;
    buttons.push_back(startButton);
    buttons.push_back(settingsButton);
    buttons.push_back(exitButton);
    return buttons;

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
    std::vector<Button> buttonsMainMenu;
    buttonsMainMenu = setUpMenu(font);
    
    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            switch (windowName) {
            case Menu:
                if (event->is<sf::Event::MouseButtonPressed>() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    menu(localPosition, buttonsMainMenu);

                }
                window.clear();
                for (Button button : buttonsMainMenu) {
                    button.Draw(window);
                } 
                
                break;
            case Start:
                break;
            case Settings:
                break;
            case Exit:
                break;
             
            }

            
        }
        window.display();

        
    }
}