#include "ResourceManager.h"
void ResourceManager::addTexture(std::string name) {
	sf::Texture* tp = new sf::Texture;
	if (!tp->loadFromFile(name + ".jpg"))
		exit(1);
	textures[name] = tp;
	delete tp;
}
sf::Texture* ResourceManager::getTexture(std::string name) {

	return textures[name];
}
