#include "SpineMace.h"
#include "Animation.h"
#include "ResourceManager.h"

SpineMace::SpineMace(Entity* player): 
	Weapon(player)
{
	ResourceManager::getInstance()->loadTexture("spinemace", "paint_spinemace.png", sf::IntRect(0,0,64,64));
	mAnimation = new Animation("spinemace", 150, 1);
}

SpineMace::~SpineMace(){}

bool SpineMace::shoot(){
	return false;
}

sf::Sprite SpineMace::getSprite(){
	return mAnimation->getSprite();
}

Entity* SpineMace::createBullet(){
	return nullptr;
}

Entity* SpineMace::getPlayer(){
	return nullptr;
}

sf::FloatRect SpineMace::getColBox(){
	return mAnimation->getSprite().getGlobalBounds();
}