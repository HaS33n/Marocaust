#pragma once
#include "AppManager.h"
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
	void updateWindow();
	void handleMouse(sf::Vector2i mousepos);
	void handleKeyboard(sf::Keyboard::Key key);

	//drzewo gry tu bedzie, prawdopodobnie w RM?
	sf::RenderWindow& m_window;
	sf::Event event;

	bool LMBP;

};

