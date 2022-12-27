#include "GameManager.h"
GameManager::GameManager(sf::RenderWindow& window) : m_window(window) {

	m_window.setFramerateLimit(300);

	float sx, sy;
	sx = float(sf::VideoMode::getDesktopMode().width) / float(3840);
	sy = float(sf::VideoMode::getDesktopMode().height) / float(2160);
	bg.setScale(sx, sy); 
	bg.setTexture(RM.loadTexture("background"));

	std::shared_ptr<Icon> ic = std::make_shared<Icon>("Terminal", RM.loadTexture("Terminal"), sf::Vector2f(0, 0),AM);
	icons["Terminal"] = ic;
	ic = std::make_shared<Icon>("Messenger", RM.loadTexture("Messenger"), sf::Vector2f(20, 20),AM);
	icons["Messenger"] = ic;
}

sf::RenderWindow& GameManager::GetWindow() {
	return m_window;
}

void GameManager::runGame() {
	while (m_window.isOpen())
	{
		while (m_window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseButtonPressed:
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
					handleMouse(sf::Mouse::getPosition(m_window));
				break;
			case sf::Event::KeyPressed:
				handleKeyboard(event.key.code);
				break;
			default:
				break;
			}
			dragApps();
			dragIcons();

		}
		
		updateWindow();
	}
}

void GameManager::handleMouse(sf::Vector2i mousepos) {
	std::cout << mousepos.x << " " << mousepos.y << std::endl;

	AM.handleMouse(m_window.mapPixelToCoords(mousepos));
		
}

void GameManager::handleKeyboard(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Escape)
		m_window.close();
	else if (key == sf::Keyboard::Key::RAlt)
		AM.addApp("Terminal");
	else if (key == sf::Keyboard::RShift)
		AM.killApp("Terminal");

	std::cout << key << std::endl;
}

void GameManager::updateWindow() {
	m_window.clear(sf::Color::White);
	m_window.draw(bg);

	for (auto& it : icons) {
		it.second->display(m_window);
	}

	for (auto& it : AM.apps) {
		it.second->display(m_window);
	}
	m_window.display();

}

void GameManager::dragApps() {
	for (auto& it : AM.apps) {
		it.second->dragWindow(event);
	}
}

void GameManager::dragIcons() {
	for (auto& it : icons) {
		it.second->dragIcon(event);
	}
}