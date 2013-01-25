#include "Player.h"
#include <SFML\Window\Keyboard.hpp>
#include "WindowManager.h"
#include "ResourceManager.h"

Player::Player(sf::Vector2f startPos): Entity(startPos)
{
	ResourceManager* r = ResourceManager::getInstance();
	r->loadTexture("downanimation", "priest_walk_forward_sprite.png", sf::IntRect(0,0,1280,128));

	mDown = new Animation("downanimation", 150, 10);
	mDown->setPosition(mPos);

	mWindow = WindowManager::getInstance()->getWindow();
	mYvel = mXvel = 2;
}


Player::~Player(void)
{
}


void Player::update()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		mPos.x += mXvel;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		mPos.x -= mXvel;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		mPos.y -= mYvel;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		mPos.y += mYvel;

	mDown->update();

}

void Player::render()
{
	mDown->setPosition(mPos);
	mWindow->draw(mDown->getSprite());
}