#include "PauseMenu.h"
#include "ResourceManager.h"
#include "WindowManager.h"

PauseMenu::PauseMenu():
	mAlive(true)
{
	mSprite.setTexture(ResourceManager::getInstance()->loadTexture("pausebg", "paint_pausebg.png", sf::IntRect(0,0,1600,900)));
}

PauseMenu::~PauseMenu(){

}

bool PauseMenu::isAlive(){
	return mAlive;
}

void PauseMenu::update(){
	input();
}

void PauseMenu::render(){
	WindowManager::getInstance()->setDefaultView();
	WindowManager::getInstance()->renderToCanvas(mSprite, 5);
}

void PauseMenu::input(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		mAlive = false;
	}
}

