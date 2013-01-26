#include "Player.h"
#include <SFML\Window\Keyboard.hpp>

Player::Player(sf::Vector2f startPos): Entity(startPos), mDown(new Animation("downanimation.png", 200, 10))
{
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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		mPos.y -= mYvel;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		mPos.y += mYvel;

	Drop(new Player(sf::Vector2f(1,1)));
	
}

void Player::render()
{

}