#include "AppManager.h"

void AppManager::addApp(std::string name) {
	std::shared_ptr<Application> appptr; {
		if (name == "Messenger")
			appptr = std::make_shared<Messenger>(name);

		else if (name == "Terminal")
			appptr = std::make_shared<Terminal>(name);

		if (appptr != nullptr) {
			apps[name] = appptr;
			std::cout << "App created: "<< name << std::endl;
		}
			
	}

}

void AppManager::killApp(std::string name) {
	auto f = apps.find(name);
	if (f != apps.end()) {
		apps.erase(f);
		std::cout << "App destroyed: "<< name << std::endl;
		slctd = nullptr;
	}
		
	
}

void AppManager::handleMouse(sf::Vector2f mousepos) {
	//wybieranie okna
	for (auto& it : apps) {
		sf::FloatRect bounds = it.second->getSprite().getGlobalBounds();
		if (bounds.contains(mousepos)) {
			slctd = it.second;
			std::cout << "selected: " << it.first << std::endl;
			
		}
	}



}