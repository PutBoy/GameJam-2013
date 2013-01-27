#include "SpineMace.h"
#include "Animation.h"
#include "ResourceManager.h"
#include "BulletSpineMace.h"
#include "Player.h"
#include <SFML\System\Vector2.hpp>
#include "MusicManager.h"



SpineMace::SpineMace(std::shared_ptr<Entity> player): 
	Weapon(player),
	mAttackSpeed(1),
	mAnimIdle("spinemaceIdle", 150, 1),
	mAnimAttackForward("spinemaceAttackForward", 50, 10),
	mAnimAttackLeft("spinemaceAttackLeft", 50, 10),
	mAnimAttackRight("spinemaceAttackRight", 50, 10),
	mAnimAttackBack("spinemaceAttackBack", 50, 10),
	mCurrentAttack(&mAnimAttackLeft)
{
	mAttacking = false;
}

SpineMace::~SpineMace()
{

}

std::shared_ptr<Entity> SpineMace::shoot(){
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
		mCurrentAttack->restart();

		mAttackTimer.restart();
		return std::make_shared<BulletSpineMace>(getPlayer()->getPos(), getPlayer()); //<------- kolla upp dennna ?

	}else{

		return nullptr;
	}
}


sf::Sprite& SpineMace::getSprite(){
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

sf::FloatRect SpineMace::getColBox(){
	return mAnimIdle.getSprite().getGlobalBounds(); // <-----------------den h�r g�r ingenting just nu. testa ?
}