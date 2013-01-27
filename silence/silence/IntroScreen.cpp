#include "StartMenu.h"
#include "StateManager.h"
#include "Game.h"
#include "ResourceManager.h"
#include "WindowManager.h"
#include "MapCollider.h"
#include "Map.h"
#include "MusicManager.h"
#include "IntroScreen.h"

IntroScreen::IntroScreen()
{
	mSprite.setTexture(ResourceManager::getInstance()->loadTexture("cutscene","images/cutscene_1_png.png",sf::IntRect(0,0,1600,900)));
	MusicManager* m = MusicManager::getInstance();
	donotContinue.restart();
}

IntroScreen::~IntroScreen(){
	
}

bool IntroScreen::isAlive(){
	return true;
}

void IntroScreen::update(){
	input();
}

void IntroScreen::render(){
	WindowManager::getInstance()->setDefaultView();
	WindowManager::getInstance()->renderToCanvas(mSprite, 5);
}

void IntroScreen::input(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && donotContinue.getElapsedTime().asSeconds() > 2){

		MusicManager::getInstance()->stopSound("intro");
		StateManager::getInstance()->add(new Game());
	}
}