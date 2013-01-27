#include "HealthBar.h"
#include <SFML\Graphics.hpp>


HealthBar::HealthBar():
	mAnimation("healthbar", 1, 1)
{
	mShape.setFillColor(sf::Color::Red);
	mShape.setSize(sf::Vector2f(100,1000));
	mShape.setPosition(1500,100);
	mWindow = WindowManager::getInstance();

}


HealthBar::~HealthBar(void)
{

}

void HealthBar::update(float health)
{
	mWindow->getView().getCenter().x;
	sf::Vector2f newPos;
	newPos.x = mWindow->getView().getCenter().x -745;
	newPos.y = mWindow->getView().getCenter().y -450;

	float healtPercentage = 1/health;
	sf::Vector2f newSize;
	newSize.x = mShape.getSize().x;
	newSize.y = 1000 - (1000*healtPercentage);

	mShape.setPosition(newPos);
	mShape.setSize(newSize);

	newPos.x = mWindow->getView().getCenter().x -800;
	newPos.y = mWindow->getView().getCenter().y -450;
	mAnimation.setPosition(newPos);

}

void HealthBar::render()
{
	
	mWindow->renderToCanvas(mAnimation.getSprite(), 5);
	mWindow->renderToCanvas(mShape, 5);
}