#include "Player.h"
#include <SFML\Window\Keyboard.hpp>
#include "ResourceManager.h"
#include "WindowManager.h"
#include "MapCollider.h"


#include <iostream>

Player::Player(sf::Vector2f startPos, MapCollider m): Entity(startPos), mMapColider(m)
{
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

	mCurrentAnim = mDown;
	mYvel = mXvel = 5;
	mWindow = WindowManager::getInstance();

	mCollisionBox.height = 64;
	mCollisionBox.width = 96;
	mCollisionBox.left = mPos.x - mCollisionBox.width / 2;
	mCollisionBox.top = mPos.y - mCollisionBox.height / 2;
	
}


Player::~Player(void)
{
}


void Player::update()
{
	sf::Vector2f distance;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mCurrentAnim = mRigth;
		distance.x += mXvel;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mCurrentAnim = mLeft;
		distance.x -= mXvel;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		mCurrentAnim = mUp;
		distance.y -= mYvel;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		mCurrentAnim = mDown;
		distance.y += mYvel;
	}


	//idle animations
	if(mCurrentAnim == mDown && distance.y == 0){
		mCurrentAnim = mDownIdle;
	}

	mPos += distance;
	mCollisionBox.left = mPos.x - mCollisionBox.width / 2;
	mCollisionBox.top = mPos.y - mCollisionBox.height / 2;
	

	sf::Vector2f move = mMapColider.tryMove(mPos, distance, mCollisionBox);
	mPos = move;

	mCurrentAnim->update();
}

void Player::render()
{
	mCurrentAnim->setPosition(mPos - sf::Vector2f(64, 96));
	mWindow->renderToCanvas(mCurrentAnim->getSprite(), 0);
}

float Player::getHP(){
	return 0.0f;
}

std::string Player::isID(std::string ID){
	return "kallke";
}

float Player::getDamage(){
	return 0.0f;
}

void Player::setHP(float damage){
}

sf::FloatRect Player::getColBox(){
	return sf::FloatRect(0,0,0,0);
}