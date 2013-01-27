#include "KnucklesPickup.h"
#include "Animation.h"
#include "ResourceManager.h"
#include "WindowManager.h"
#include "Knuckles.h"
#include "Player.h"
#include "Entity.h"

#include <iostream>

KnucklesPickup::KnucklesPickup(sf::Vector2f startPos):
	Pickup(startPos), mAnimation("spinemace",150,1)
{
	pushID("SpineMace");
	mAnimation.setPosition(startPos);
}

KnucklesPickup::~KnucklesPickup()
{
}

void KnucklesPickup::update(){}

void KnucklesPickup::render(){
	WindowManager::getInstance()->renderToCanvas(mAnimation.getSprite(), -1);
}


sf::FloatRect KnucklesPickup::getColBox(){

	//testa om denna funkar. borde funka men har haft problem tidigare.

	return mAnimation.getSprite().getGlobalBounds();
}

void KnucklesPickup::ResolveCollision(std::shared_ptr<Entity> entity){
	
		std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(entity);
			
				player->setWep(std::make_shared<Knuckles>(entity)); 
				
			
		}
