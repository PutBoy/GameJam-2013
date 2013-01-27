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
	mAnimIdle("spinemaceIdle", 150, 1), mAnimAttack("spinemaceAttackForward", 100, 10)
{
	mAttacking = false;
}

SpineMace::~SpineMace()
{

}

std::shared_ptr<Entity> SpineMace::shoot(){
	sf::Vector2f vec = (std::dynamic_pointer_cast<Player>(getPlayer()))->getDirection();



	if(mAttackTimer.getElapsedTime().asSeconds() > mAttackSpeed){
		MusicManager* musica = MusicManager::getInstance();
		musica->loadSound("ljud","Enemy_hit1.wav");
		musica->playSound("ljud");
		mAttacking = true;
		mAnimAttack.restart();

		mAttackTimer.restart();
		return std::make_shared<BulletSpineMace>(getPlayer()->getPos(), getPlayer()); //<------- kolla upp dennna ?

	}else{

		return nullptr;
	}
}


sf::Sprite& SpineMace::getSprite(){
	if (mAnimAttack.loopAmounts() >= 1)
		mAttacking = false;

	int pX = getPlayer()->getXpos();
	int pY = getPlayer()->getYpos();

	mAnimIdle.getSprite().setPosition(
		pX - mAnimIdle.getSprite().getTextureRect().width / 2,
		pY - mAnimIdle.getSprite().getTextureRect().height / 2);
	mAnimIdle.update();
	
	mAnimAttack.getSprite().setPosition(
		pX - mAnimAttack.getSprite().getTextureRect().width / 2,
		pY - mAnimAttack.getSprite().getTextureRect().height / 2);
	mAnimAttack.update();

	if (mAttacking)
		return mAnimAttack.getSprite();
	else
		return mAnimIdle.getSprite();
}

sf::FloatRect SpineMace::getColBox(){
	return mAnimIdle.getSprite().getGlobalBounds();
}