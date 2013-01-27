#include "Player.h"
#include <SFML\Window\Keyboard.hpp>
#include "ResourceManager.h"
#include "WindowManager.h"
#include "MapCollider.h"



#include "Weapon.h"

#include <iostream>

Player::Player(sf::Vector2f startPos, MapCollider m): Entity(startPos), mMapColider(m),
	mWeapon(nullptr)
{
	pushID("Player");
	mHP = 100;
	ResourceManager* r = ResourceManager::getInstance();
	r->loadTexture("down","priest_walk_forward_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("left","priest_walk_left_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("right","priest_walk_right_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("up","priest_walk_back_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("downIdle", "priest_stand_still_sprite.png", sf::IntRect(0,0,1280,128));

	mDown = new Animation("down",150,10);
	mLeft = new Animation("left",150,10);
	mRigth = new Animation("right",150,10);
	mUp = new Animation("up",150,10);

	mDownIdle = new Animation("downIdle", 150, 10);
	mDirection = sf::Vector2f(0.0, mYvel);
	mCurrentAnim = mDown;
	mYvel = mXvel = 5;
	mWindow = WindowManager::getInstance();

	mCollisionBox.height = 64;
	mCollisionBox.width = 64;
	mCollisionBox.left = mPos.x - mCollisionBox.width / 2;
	mCollisionBox.top = mPos.y - mCollisionBox.height / 2  - 64;
	mHealthBar = new HealthBar();
}


Player::~Player(void)
{
}


void Player::update()
{


	//spelar-attack vanlig <-----------
	attack();


	sf::Vector2f distance; 
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mCurrentAnim = mRigth;
		distance.x += mXvel;
		mDirection = sf::Vector2f(mXvel,0.0);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mCurrentAnim = mLeft;
		distance.x -= mXvel;
		mDirection = sf::Vector2f(mXvel,0.0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		mCurrentAnim = mUp;
		distance.y -= mYvel;
		mDirection = sf::Vector2f(0.0,mYvel);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		mCurrentAnim = mDown;
		distance.y += mYvel;
		mDirection = sf::Vector2f(0.0,mYvel);
	}
	
	


	//idle animations
	if(mCurrentAnim == mDown && distance.y == 0){
		mCurrentAnim = mDownIdle;
	}

	mPos += distance;
	mCollisionBox.left = mPos.x - mCollisionBox.width / 2;
	mCollisionBox.top = mPos.y - mCollisionBox.height / 2 + 32;
	
	sf::Vector2f move = mMapColider.tryMove(sf::Vector2f(mPos.x, mPos.y + 32), distance, mCollisionBox);
	mPos = sf::Vector2f(move.x, move.y - 32) ;

	mCurrentAnim->update();
	mHealthBar->update(mHP);
	if(mHP <= 0){
	kill();
	}
}

void Player::render()
{
	mCurrentAnim->setPosition(mPos - sf::Vector2f(64, 64));
	mWindow->renderToCanvas(mCurrentAnim->getSprite(), 0);
	if(mWeapon != nullptr){
		mWindow->renderToCanvas(mWeapon->getSprite(), 1);
	};
	mHealthBar->render();
}

void Player::doDamage(float damage){
mHP -= damage;
}

sf::FloatRect Player::getColBox(){
	return mCollisionBox;
}

sf::Vector2f Player::getDirection(){ // <------------vet ej om denna ska vara här ?

return mDirection;
}




void Player::ResolveCollision(Entity* entity)
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

void Player::setWep(Weapon* weapon){
	
	mWeapon = weapon;
}

void Player::attack(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && mWeapon != nullptr){ //<----------------------------gör en stack här
		Drop(mWeapon->shoot());
	}
}
