#include "Knuckles.h"
#include "Animation.h"
#include "ResourceManager.h"


Knuckles::Knuckles(std::shared_ptr<Entity> player):
Weapon(player), mAnimation("Knuckles", 150, 10)

{

}


Knuckles::~Knuckles(void)
{
}

std::shared_ptr<Entity> Knuckles::shoot(){
	return nullptr;
}

sf::Sprite& Knuckles::getSprite(){
	return mAnimation.getSprite();
}

std::shared_ptr<Entity> Knuckles::createBullet(){
	return nullptr;
}

std::shared_ptr<Entity> Knuckles::getPlayer(){
	return nullptr;
}

sf::FloatRect Knuckles::getColBox(){
	return mAnimation.getSprite().getGlobalBounds();
}