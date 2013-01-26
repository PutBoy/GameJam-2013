#include "SpineMacePickup.h"
#include "Animation.h"
#include "ResourceManager.h"
#include "WindowManager.h"
#include "SpineMace.h"
#include "Player.h"
#include "Entity.h"

SpineMacePickup::SpineMacePickup(sf::Vector2f startPos):
	Pickup(startPos)
{
	pushID("SpineMace");
	ResourceManager::getInstance()->loadTexture("SpineMace","blablalb pickup.png", sf::IntRect(0,0,500,500));
	mAnimation = new Animation("pickup", 150, 10);
	mAnimation->setPosition(startPos);
}

SpineMacePickup::~SpineMacePickup(){}

void SpineMacePickup::update(){}

void SpineMacePickup::render(){
	WindowManager::getInstance()->renderToCanvas(mAnimation->getSprite(), 0);
}

std::string SpineMacePickup::isID(std::string){
	return "kalle";
}

sf::FloatRect SpineMacePickup::getColBox(){

	//testa om denna funkar. borde funka men har haft problem tidigare.

	return mAnimation->getSprite().getGlobalBounds();
}

void SpineMacePickup::ResolveCollision(Entity* entity){
	if(entity->isID("Player")){
		Player* player = static_cast<Player*>(entity);
		player->setWep(new SpineMace(player)); // player går kanske ur scoope `?
	}
}