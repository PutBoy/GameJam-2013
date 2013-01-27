#include "Player.h"
#include <SFML\Window\Keyboard.hpp>
#include "ResourceManager.h"
#include "WindowManager.h"
#include "MapCollider.h"
#include "MusicManager.h"
#include "Knuckles.h"
#include "Weapon.h"
#include "AnimationEntity.h"
#include <iostream>


Player::Player(sf::Vector2f startPos, MapCollider m): Entity(startPos), mMapColider(m),
	mWeapon(nullptr), 
	mDown("down",150,10) ,mLeft("left",150,10) , mRigth("right",150,10) ,mUp("up",150,10), 
	mDownIdle("downIdle", 150, 10)
	,mUpIdle("BackIdle1",500,1), mLeftIdle("leftIdle",500,1), mRigthIdle("rigthIdle1",500,1)
	
{
	pushID("Player");
	mHP = 100;

	mDirection = sf::Vector2f(0.0, mYvel);
	mCurrentAnim = &mDown;
	mYvel = mXvel = 5;
	mWindow = WindowManager::getInstance();

	mCollisionBox.height = 64;
	mCollisionBox.width = 64;
	mCollisionBox.left = mPos.x - mCollisionBox.width / 2;
	mCollisionBox.top = mPos.y - mCollisionBox.height / 2  - 64;
	mHealthBar = new HealthBar();
	mDeathAnim = new AnimationEntity(mPos,"deathanimationenemy",10,10);
}


Player::~Player(void)
{
}


void Player::update()
{

	sf::Vector2f distance;

	

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mCurrentAnim = &mRigth;
		distance.x += mXvel;
		mDirection = sf::Vector2f(mXvel,0.0);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mCurrentAnim = &mLeft;
		distance.x -= mXvel;
		mDirection = sf::Vector2f(mXvel,0.0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		mCurrentAnim = &mUp;
		distance.y -= mYvel;
		mDirection = sf::Vector2f(0.0,mYvel);
	

	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		mCurrentAnim = &mDown;
		distance.y += mYvel;
		mDirection = sf::Vector2f(0.0,mYvel);
	}


	
	float length = ((mDirection.x*mDirection.x)+(mDirection.y*mDirection.y));
	length = sqrt(length);
	if(length == 0.0) length = 0.0001f;

	mDirection.x = mDirection.x/length;
	mDirection.y = mDirection.y/length;

	
	
	//idle animations
	if(mCurrentAnim == &mDown && distance.y == 0)
	{
		mCurrentAnim = &mDownIdle;
	}
	else if(mCurrentAnim == &mUp && distance.y == 0)
	{
		mCurrentAnim = &mUpIdle;
	}
	if(mCurrentAnim == &mLeft && distance.x == 0)
	{
		mCurrentAnim = &mLeftIdle;
	}
	else if(mCurrentAnim == &mRigth && distance.x == 0)
	{
		mCurrentAnim = &mRigth;
	}

	mPos += distance;
	mCollisionBox.left = mPos.x - mCollisionBox.width / 2;
	mCollisionBox.top = mPos.y - mCollisionBox.height / 2 + 32;
	
	sf::Vector2f move = mMapColider.tryMove(sf::Vector2f(mPos.x, mPos.y + 32), distance, mCollisionBox);
	mPos = sf::Vector2f(move.x, move.y - 32) ;

	mDir = distance;

	mCurrentAnim->update();

	//spelar-attack vanlig <-----------
	attack();

	mHealthBar->update(mHP);

	if(mHP <= 0 && !isDead()){
		deathTimer.restart();
		kill();

	}
}

void Player::render()
{
	mCurrentAnim->setPosition(mPos - sf::Vector2f(64, 64));
	mWindow->renderToCanvas(mCurrentAnim->getSprite(), 0);
	if(mWeapon != nullptr){
		mWindow->renderToCanvas(mWeapon->getSprite(), 1);
	}
	if(mHP <= 0)
	{
		mDeathAnim->update();
		mDeathAnim->render();
	}
	mHealthBar->render();
}

void Player::doDamage(float damage){
mHP -= damage;
}

sf::FloatRect Player::getColBox(){
	return mCollisionBox;
}

sf::Vector2f Player::getDirection(){ 
	return mDirection;
}

sf::Clock& Player::deadforTime()
{
	return deathTimer;
}

void Player::ResolveCollision(std::shared_ptr<Entity> entity)
{
	sf::Vector2f newPos(entity->getXpos(),entity->getYpos());
	sf::Vector2f distance = distanceRectToRect(entity->getColBox(), mCollisionBox);
	sf::Vector2f major = getMajorVector(distance);

	sf::FloatRect entbox = entity->getColBox();

	if (major.x < -.5)
	{
		newPos.x -= distance.x; //entbox.left - mCollisionBox.width / 2;
		entbox.left = mPos.x - mCollisionBox.width / 2;
	}
	else if (major.x > .5)
	{
		newPos.x -= distance.x;// entbox.left + entbox.width + mCollisionBox.width / 2;
		entbox.left = mPos.x - mCollisionBox.width / 2;
	}
	else if (major.y < -.5)
	{
		newPos.y -= distance.y;// entbox.top - mCollisionBox.height / 2;
		entbox.top = mPos.y - mCollisionBox.height / 2;
	}
	else if (major.y > .5)
	{
		newPos.y -= distance.y;// entbox.top + entbox.height + mCollisionBox.height / 2;
		entbox.top = mPos.y - mCollisionBox.height / 2;
	}
	entity->setPos(newPos);
}

void Player::setWep(std::shared_ptr<Weapon> weapon){
	mWeapon = weapon;
}

void Player::attack(){
	
	
	std::shared_ptr<Knuckles> knuck;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && mWeapon != nullptr){
															//<----------------------------gör en stack här
		std::shared_ptr<Entity> drop = mWeapon->shoot();
		if (drop)
			Drop(drop);
	}
	 if(mWeapon == nullptr)
		 mWeapon = knuck;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		std::shared_ptr<Entity> drop = mWeapon->shoot();
		if (drop)
			Drop(drop);
		mWeapon == nullptr;
	}
}


sf::Vector2f Player::getDir(){
	return mDir;
}