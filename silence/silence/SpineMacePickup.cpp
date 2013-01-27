#include "SpineMacePickup.h"
#include "Animation.h"
#include "ResourceManager.h"
#include "WindowManager.h"
#include "SpineMace.h"
#include "Player.h"
#include "Entity.h"

#include <iostream>

SpineMacePickup::SpineMacePickup(sf::Vector2f startPos, MapCollider m):
	Pickup(startPos, m), mAnimation("spinemace",150,1)
{
	pushID("SpineMace");
	mAnimation.setPosition(startPos);
}

SpineMacePickup::~SpineMacePickup()
{
	delete mAnimation;
}

void SpineMacePickup::update(){}

void SpineMacePickup::render(){
	WindowManager::getInstance()->renderToCanvas(mAnimation.getSprite(), -1);
}


sf::FloatRect SpineMacePickup::getColBox(){

	//testa om denna funkar. borde funka men har haft problem tidigare.

	return mAnimation.getSprite().getGlobalBounds();
}

void SpineMacePickup::ResolveCollision(std::shared_ptr<Entity> entity){
	if(entity->isID("Player") && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(entity);
			if (player)
			{
				player->setWep(std::make_shared<SpineMace>(entity)); 
				kill();
			}
		}
}