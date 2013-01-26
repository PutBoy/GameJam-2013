#include "Player.h"
#include <SFML\Window\Keyboard.hpp>
#include "ResourceManager.h"
#include "WindowManager.h"


Player::Player(sf::Vector2f startPos): Entity(startPos)
{
	ResourceManager* r = ResourceManager::getInstance();
	r->loadTexture("down","priest_walk_forward_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("left","priest_walk_left_sprite.png",sf::IntRect(0,0,1280,128));
	r->loadTexture("right","priest_walk_right_sprite.png",sf::IntRect(0,0,1280,128));
	mDown = new Animation("down",150,10);
	mLeft = new Animation("left",150,10);
	mRight = new Animation("right",150,10);

	mCurrentAnim = mDown;
	mYvel = mXvel = 5;

	mWindow = WindowManager::getInstance()->getWindow();
}


Player::~Player(void)
{
}


void Player::update()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mCurrentAnim = mDown;
		mPos.x += mXvel;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mCurrentAnim = mDown;
		mPos.x -= mXvel;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		mCurrentAnim = mDown;
		mPos.y -= mYvel;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		mPos.y += mYvel;
	}

	mCurrentAnim->update();
}

void Player::render()
{
	mCurrentAnim->setPosition(mPos);
	mWindow->draw(mCurrentAnim->getSprite());
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