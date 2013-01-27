#include "Knuckles.h"

#include "ResourceManager.h"
#include "BulletKnuckles.h"
#include "Player.h"
#include <SFML\System\Vector2.hpp>
#include "MusicManager.h"


Knuckles::Knuckles(std::shared_ptr<Entity> player):
Weapon(player), mAnimIdle("images/priest_idle_back_png", 150, 1),
	mAnimAttackForward("images/priest_PunchDown", 150, 10),
	mAnimAttackBack("images/priest_PunchUp", 150, 10),
	mAnimAttackLeft("images/priest_PunchLeft", 150, 10),
	mAnimAttackRight("images/priest_PunchRight", 150, 10),
	mAnimFel("nullptr", 1, 1),
	mCurrentAttack(&mAnimAttackLeft),
	mKillCounter(10)
{

}


Knuckles::~Knuckles(void)
{
}

std::shared_ptr<Entity> Knuckles::shoot(){
	sf::Vector2f dir = (std::dynamic_pointer_cast<Player>(getPlayer()))->getDir();

	if(dir.x == 5){
		mCurrentAttack = &mAnimAttackRight;
	}else if(dir.x == -5){
		mCurrentAttack = &mAnimAttackLeft;
	}else if(dir.y == 5){
		mCurrentAttack = &mAnimAttackForward;
	}else if(dir.y == -5){
		mCurrentAttack = &mAnimAttackBack;
	}


	if(mAttackTimer.getElapsedTime().asSeconds() > mAttackSpeed){
		MusicManager* musica = MusicManager::getInstance();
		musica->loadSound("ljud","Enemy_hit1.wav");
		musica->playSound("ljud");
		mAttacking = true;

		mKillCounter--;
		if(mKillCounter <= 0){
			mAnimIdle = mAnimFel;
			return nullptr;
		}

		mCurrentAttack->restart();
		mAttackTimer.restart();
		return std::make_shared<BulletKnuckles>(getPlayer()->getPos(), getPlayer()); //<------- kolla upp dennna ?

	}else{

		return nullptr;
	}
}
}

sf::Sprite& Knuckles::getSprite(){
		if (mCurrentAttack->loopAmounts() >= 1)
		mAttacking = false;

	int pX = getPlayer()->getXpos();
	int pY = getPlayer()->getYpos();

	mAnimIdle.getSprite().setPosition(
		pX - mAnimIdle.getSprite().getTextureRect().width / 2,
		pY - mAnimIdle.getSprite().getTextureRect().height / 2);
	mAnimIdle.update();
	
	mCurrentAttack->getSprite().setPosition(
		pX - mCurrentAttack->getSprite().getTextureRect().width / 2,
		pY - mCurrentAttack->getSprite().getTextureRect().height / 2);
	mCurrentAttack->update();

	if (mAttacking)
		return mCurrentAttack->getSprite();
	else
		return mAnimIdle.getSprite();
}




std::shared_ptr<Entity> Knuckles::getPlayer(){
	return nullptr;
}

sf::FloatRect Knuckles::getColBox(){
	return mAnimIdle.getSprite().getGlobalBounds();
}