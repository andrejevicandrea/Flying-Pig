#include <SFML/Graphics.hpp>
#include "Button.h"
#include <vector>
#include <unordered_map>

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
                std::cout << "Start\n";
            }
            if (buttonName == "Settings") {
                windowName = Settings;
                std::cout << "Settings\n";
            }
            if (buttonName == "Exit") {
                windowName = Exit;
                std::cout << "Exit\n";
            }
        }
    }

}

void settings(const sf::Vector2i& localPosition, std::unordered_map<std::string, Button>& buttonsSettingsMenu) {
    for (auto it = buttonsSettingsMenu.begin(); it != buttonsSettingsMenu.end(); it++) {
        if (checkButton(it->second, localPosition)) {
            if (it->first == "backToMenu") {
                windowName = Menu;
            }
            else if (it->first == "checkBox") {
                std::string text = it->second.GetText();
                if (text == "X") {
                    (it->second).SetText("");

                }
                else {
                    (it->second).SetText("X");
                    it->second.CenterText();
                }   
            }
           
        }
    }
    
}

std::vector<Button> setUpMainMenu(const sf::Font& font) {
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

std::unordered_map<std::string, Button> setUpSettingsMenu(const sf::Font& font) {
    
    std::unordered_map<std::string, Button> buttons;

    //first line: Music and check box
    sf::Text music(font, "Music");
    music.setPosition(sf::Vector2f(300.0f, 250.0f));
    sf::FloatRect musicBounds = music.getLocalBounds();
    //std::cout << musicBounds.position.x << " " << musicBounds.position.y << "\n";
    float positionX = music.getPosition().x + musicBounds.size.x + 30.0f;
    float positionY = music.getPosition().y + (musicBounds.size.y - 10.0f) / 2.0f;
    sf::Text emptyText(font, "", 20U);
    Button checkBox(sf::Vector2f(positionX, positionY), sf::Vector2f(20.0f, 20.0f), emptyText);

    buttons.insert(std:: pair("checkBox",checkBox));

    //second line: slider
    sf::Text volume(font, "Volume");
    volume.setPosition(sf::Vector2f(300.0f, 351.0f));
    sf::FloatRect volumeBounds = volume.getLocalBounds();
    positionX = volume.getPosition().x + volumeBounds.size.x + 30.0f;
    positionY = volume.getPosition().y + (volumeBounds.size.y) / 2.0f;
    Button sliderLine(sf::Vector2f(positionX, positionY), sf::Vector2f(130.0f, 3.0f), emptyText);
    Button slider(sf::Vector2f(positionX, positionY - 15.0f), sf::Vector2f(10.0f, 30.0f), emptyText);

    buttons.insert(std::pair("sliderLine", sliderLine));
    buttons.insert(std::pair("slider", slider));
    

    //third line: Back to manu button
    sf::Text backText(font, "Back to menu");
    Button backToMenu(sf::Vector2f(300.0f, 452.0f), sf::Vector2f(200, 100), backText);

    buttons.insert(std::pair("backToMenu", backToMenu));

    return buttons;

}


int main()
{

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "Flying Pig", sf::Style::Resize | sf::Style::Close, sf::State::Windowed);
    window.setPosition(sf::Vector2i(600 + 1920, 100));
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Font font;
    if (!font.openFromFile("Anton-Regular.ttf")) {
        return -1;
    }
    std::vector<Button> buttonsMainMenu;
    std::unordered_map<std::string, Button> buttonsSettingsMenu;
    buttonsMainMenu = setUpMainMenu(font);
    buttonsSettingsMenu = setUpSettingsMenu(font);
    sf::Texture texture;
    if (!texture.loadFromFile("slika.jpg")) {
        return -1;
    }
    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (windowName == Menu) {

                if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonReleased>()) {
                    if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
                        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                        menu(localPosition, buttonsMainMenu);

                    }
                }

            }
            if (windowName == Settings) {
                if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonReleased>()) {
                    if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
                        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                        settings(localPosition, buttonsSettingsMenu);


                    }
                }

            }
            if (windowName == Exit) {
                window.close();
            }

        }
        window.clear();
        if (windowName == Menu) {
            for (Button button : buttonsMainMenu) {
                button.Draw(window);
            }

        }
        else if (windowName == Start) {
            window.clear();
            window.draw(sprite);

        }
        else if (windowName == Settings) {

            window.clear();
            sf::Text music(font, "Music");
            music.setPosition(sf::Vector2f(300.0f, 250.0f));
            window.draw(music);

            sf::Text volume(font, "Volume");
            volume.setPosition(sf::Vector2f(300.0f, 351.0f));
            window.draw(volume);

            for (const auto& pair : buttonsSettingsMenu) {
                ((Button) pair.second).Draw(window);
                //std::cout << ((Button)pair.second).GetText() << "\n";
            }

        }
        window.display();


    }
}
