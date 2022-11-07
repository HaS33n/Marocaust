#include "Application.h"

Application::Application(std::string title) : name(title)
{

	baseTX.create(500, 330);
	baseTX.clear();
	sf::RectangleShape mainWindow(sf::Vector2f(500, 300));
	mainWindow.setFillColor(sf::Color::Black);

	sf::RectangleShape bar(sf::Vector2f(500, 30));
	bar.setFillColor(sf::Color::Cyan);
	baseTX.draw(mainWindow);
	baseTX.draw(bar);
	baseTX.display();
	sprt.setTexture(baseTX.getTexture());
}

void Application::display(sf::RenderWindow& tW) {
	tW.draw(sprt);
}

sf::Sprite& Application::getSprite() {
	return sprt;
}

void Application::moveWindow(sf::Vector2f position) {
	sprt.setPosition(position);
}

void Application::moveWindow(float x, float y) {
	sprt.setPosition(x, y);
}

sf::RenderTexture& Application::getSpriteTexture() {
	return baseTX;
}

void Application::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprt);
}


