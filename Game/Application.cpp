#include "Application.h"

Application::Application(std::string title) : name(title)
{
	window.setFillColor(sf::Color::Yellow);
	window.setSize(sf::Vector2f(100, 100));
}

void Application::display() {

}

sf::RectangleShape& Application::getWindow() {
	return window;
}

void Application::moveWindow(sf::Vector2f position) {

}

void Application::moveWindow(float x, float y) {

}

void Application::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(window);
}


