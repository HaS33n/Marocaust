#include "Application.h"

Application::Application(std::string title) : name(title)
{
	isBeingDreagged = false;

	baseTX.create(500, 330);
	baseTX.clear();
	sf::RectangleShape mainWindow(sf::Vector2f(500, 300));
	mainWindow.setFillColor(sf::Color::Black);

	sf::RectangleShape bar(sf::Vector2f(500, 30));
	bar.setFillColor(sf::Color::Cyan);
	baseTX.draw(mainWindow);
	baseTX.draw(bar);
	baseTX.display();
	window.setTexture(baseTX.getTexture());
}

void Application::display(sf::RenderWindow& tW) {
	tW.draw(window);
}

sf::Sprite& Application::getSprite() {
	return window;
}

sf::RenderTexture& Application::getSpriteTexture() {
	return baseTX;
}

void Application::dragWindow(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // Check if the mouse is over the sprite
        if (window.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            isBeingDreagged = true;
            dragOffset = sf::Vector2f(event.mouseButton.x, event.mouseButton.y) - window.getPosition();
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased)
    {
       isBeingDreagged = false;
    }
    else if (event.type == sf::Event::MouseMoved && isBeingDreagged)
    {
        // Update the sprite's position while it is being dragged
        window.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y) - dragOffset);
    }
 }

void Application::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(window);
}


