#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>

int main() 
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Marocaust", sf::Style::Fullscreen);
	GameManager GM(window);
	GM.runGame();

	return 0;
}