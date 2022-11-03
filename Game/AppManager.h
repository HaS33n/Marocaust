#pragma once
#include "Application.h"
#include  "Messenger.h"
#include "Terminal.h"
#include <unordered_map>
#include <iostream>
enum class appType{mess,terminal};
class AppManager
{
public:
	friend class GameManager;
	void addApp(std::string name);
	void killApp(std::string name);
	void moveApp(std::string name, sf::Vector2f position);
	void moveApp(std::string name, float x, float y);
	void handleMouse(sf::Event evnt,sf::Vector2f mousepos);
private:
	std::unordered_map<std::string, std::shared_ptr<Application>> apps;
	std::shared_ptr<Application> slctd;

};

