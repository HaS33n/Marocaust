#include "ResourceManager.h"
bool ResourceManager::addTexture(std::string name) {
	sf::Texture* tp = new sf::Texture;
	if (!tp->loadFromFile(name + ".jpg"))
		return false;
	textures[name] = tp;
	delete tp;
	return true;
}
sf::Texture* ResourceManager::getTexture(std::string name) {

	return textures[name];
}
