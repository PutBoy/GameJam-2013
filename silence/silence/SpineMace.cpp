#include "SpineMace.h"
#include "Animation.h"
#include "ResourceManager.h"

SpineMace::SpineMace(Entity* player): 
	Weapon(player)
{
	ResourceManager::getInstance()->loadTexture("spinemace", "bonemace_idle_png.png", sf::IntRect(0,0,256,256));
	mAnimation = new Animation("spinemace", 150, 1);
}

SpineMace::~SpineMace()
{}

bool SpineMace::shoot(){
	return false;
}

sf::Sprite& SpineMace::getSprite(){
	int pX = getPlayer()->getXpos();
	int pY = getPlayer()->getYpos();

	mAnimation->getSprite().setPosition(
		pX - mAnimation->getSprite().getTextureRect().width / 2,
		pY - mAnimation->getSprite().getTextureRect().height / 2);

	return mAnimation->getSprite();
}

Entity* SpineMace::createBullet(){
	return nullptr;
}


sf::FloatRect SpineMace::getColBox(){
	return mAnimation->getSprite().getGlobalBounds();
}