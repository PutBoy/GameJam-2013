#include "SpineMace.h"
#include "Animation.h"
#include "ResourceManager.h"
//#include "BulletSpineMace.h"

SpineMace::SpineMace(Entity* player): 
	Weapon(player)
{
	ResourceManager::getInstance()->loadTexture("spinemace", "bonemace_idle_png.png", sf::IntRect(0,0,256,256));
	mAnimation = new Animation("spinemace", 150, 1);
}

SpineMace::~SpineMace()
{}

Entity* SpineMace::shoot(){
	//return new BulletSpineMace(getPlayer()->getPos(), getPlayer()); //<------- kolla upp dennna ?
	return nullptr;
}

Entity* SpineMace::specialShoot(){
	//return new BulletSpineMace(getPlayer()->getPos(), getPlayer()); //<------- kolla upp dennna ?
	return nullptr;
}

sf::Sprite& SpineMace::getSprite(){
	int pX = getPlayer()->getXpos();
	int pY = getPlayer()->getYpos();

	mAnimation->getSprite().setPosition(
		pX - mAnimation->getSprite().getTextureRect().width / 2,
		pY - mAnimation->getSprite().getTextureRect().height / 2);

	return mAnimation->getSprite();
}

sf::FloatRect SpineMace::getColBox(){
	return mAnimation->getSprite().getGlobalBounds();
}