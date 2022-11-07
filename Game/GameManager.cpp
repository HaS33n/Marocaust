#include "GameManager.h"
GameManager::GameManager(sf::RenderWindow& window) : m_window(window) {
	//wczytanie konfiguracji

	/*
	std::fstream cfg;
	cfg.open("config.cfg",std::ios::in);
	if (!cfg.good())
		exit(2);


	cfg.close();

	*/

	m_window.setFramerateLimit(144);
	LMBP = false;
	//test
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
			case sf::Event::MouseButtonReleased:
				LMBP = false;
				break;
			case sf::Event::KeyPressed:
				handleKeyboard(event.key.code);
				break;
			default:
				break;
			}

		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (LMBP) 
				AM.moveApp(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)));

				
		}
		updateWindow();
	}
}

void GameManager::handleMouse(sf::Vector2i mousepos) {
	std::cout << mousepos.x << " " << mousepos.y << std::endl;
	//je¿eli nie kliknê³o w cokolwiek za co odpowiada GM to musia³o to byæ okno aplikacji wiec ono AM sie tym zajmie
	//todo
	LMBP=AM.handleMouse(m_window.mapPixelToCoords(mousepos));
	if (LMBP && AM.slctd != nullptr) {
		AM.slctd->getSprite().setOrigin(AM.slctd->getSpriteTexture().mapPixelToCoords(mousepos));
	}
		
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

	for (auto& it : AM.apps) {
		it.second->display(m_window);
	}

	m_window.display();
}