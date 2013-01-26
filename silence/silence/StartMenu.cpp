#include "StartMenu.h"
#include "StateManager.h"
#include "Game.h"
#include "ResourceManager.h"
#include "WindowManager.h"

StartMenu::StartMenu(){
	mSprite.setTexture(ResourceManager::getInstance()->loadTexture("background","paint_background.png",sf::IntRect(0,0,1200,600)));
}

StartMenu::~StartMenu(){
	
}

bool StartMenu::isAlive(){
	return true; // blablalblab
}

void StartMenu::update(){
	input();
}

void StartMenu::render(){
	WindowManager::getInstance()->renderToCanvas(mSprite, 5);
}

void StartMenu::input(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		StateManager::getInstance()->add(new Game());
	}
}