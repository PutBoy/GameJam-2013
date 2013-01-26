#include "Player.h"
#include <SFML\Window\Keyboard.hpp>
#include "ResourceManager.h"
#include "WindowManager.h"


Player::Player(sf::Vector2f startPos): Entity(startPos)
{
	ResourceManager* r = ResourceManager::getInstance();
	r->loadTexture("down","priest_walk_forward_sprite.png",sf::IntRect(0,0,1280,128));
	mDown = new Animation("down",150,10);
	mCurrentAnim = mDown;
	mYvel = mXvel = 2;

	mWindow = WindowManager::getInstance()->getWindow();
}


Player::~Player(void)
{
}


void Player::update()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mPos.x += mXvel;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
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

	Drop(new Player(sf::Vector2f(1,1)));
	
	mCurrentAnim->update();
}

void Player::render()
{
	mCurrentAnim->setPosition(mPos);
	mWindow->draw(mCurrentAnim->getSprite());
}