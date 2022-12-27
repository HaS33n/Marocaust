#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "AppManager.h"

class Icon : public sf::Drawable
{
public:
	Icon(std::string name, sf::Texture& tx, sf::Vector2f Position, static AppManager& am);
	void dragIcon(const sf::Event& event); //te¿ bêdzie podwójnym klikniêciem
	void display(sf::RenderWindow& tW);
	
	
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void startApp();


	sf::Clock clock;
	sf::Time t1;

	std::string name;
	sf::Sprite sprite;

	bool isBeingDragged;
	sf::Vector2f dragOffset;

	AppManager& AM;
};

