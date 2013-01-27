#include "Knuckles.h"
#include "Animation.h"
#include "ResourceManager.h"

Knuckles::Knuckles(Entity* player):
Weapon(player), mAnimation("Knuckles", 150, 10)
{

}


Knuckles::~Knuckles(void)
{
}

Entity* Knuckles::shoot(){
return false;
}

sf::Sprite& Knuckles::getSprite(){
	return mAnimation.getSprite();
}

Entity* Knuckles::createBullet(){
	return nullptr;
}

Entity* Knuckles::getPlayer(){
	return nullptr;
}

sf::FloatRect Knuckles::getColBox(){
	return mAnimation.getSprite().getGlobalBounds();
}