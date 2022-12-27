#pragma once
#include "AppManager.h"
#include "ResourceManager.h"
#include "Icon.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class GameManager
{
public:
    GameManager(sf::RenderWindow& window);
    sf::RenderWindow& GetWindow();
    void runGame();

private:
    AppManager AM;
    ResourceManager RM;

    void updateWindow();
    void dragApps();
    void dragIcons();
    void handleMouse(sf::Vector2i mousepos);
    void handleKeyboard(sf::Keyboard::Key key);

    std::unordered_map<std::string, std::shared_ptr<Icon>> icons;

    sf::RenderWindow& m_window;
    sf::Event event;
    sf::Sprite bg;
};