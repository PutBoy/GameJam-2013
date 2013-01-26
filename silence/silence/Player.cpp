#include "Player.h"
#include <SFML\Window\Keyboard.hpp>
#include "ResourceManager.h"
#include "WindowManager.h"
#include "MapCollider.h"

Player::Player(sf::Vector2f startPos): Entity(startPos)
{
	ResourceManager* r = ResourceManager::getInstance();
	r->loadTexture("down","priest_walk_forward_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("left","priest_walk_left_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("right","priest_walk_right_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("up","priest_walk_back_sprite.png",sf::IntRect(0,0,1280,128));
	mDown = new Animation("down",150,10);
	mLeft = new Animation("left",150,10);
	mRigth = new Animation("right",150,10);
	mUp = new Animation("up",150,10);

	mCurrentAnim = mDown;
	mYvel = mXvel = 5;
	mWindow = WindowManager::getInstance();

	mCollisionBox.height = 128;
	mCollisionBox.width = 128;
	mCollisionBox.top = mPos.y;
	mCollisionBox.left = mPos.x;
}


Player::~Player(void)
{
	delete mMapColider;
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

	mPos += distance;
	mCollisionBox.left = mPos.x;
	mCollisionBox.top = mPos.y;
	

	sf::Vector2f move = mMapColider->tryMove(mPos, distance, mCollisionBox);
	mPos = move;

	mCurrentAnim->update();
}

void Player::render()
{
	mCurrentAnim->setPosition(mPos);
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