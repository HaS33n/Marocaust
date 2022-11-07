#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
class ResourceManager
{
public:
	bool addTexture(std::string name);
	sf::Texture* getTexture(std::string name);
private:
	std::unordered_map<std::string, sf::Texture*> textures;
};

