#include "WindowManager.h"

WindowManager::WindowManager(){
	mWindow = new sf::RenderWindow(sf::VideoMode(1600,900), "HeartBeater", sf::Style::Default);
	mWindow->setFramerateLimit(60);
}

WindowManager::~WindowManager(){}

WindowManager* WindowManager::getInstance(){
	static WindowManager instance;
	return &instance;
}

sf::RenderWindow* WindowManager::getWindow(){
	return mWindow;
}