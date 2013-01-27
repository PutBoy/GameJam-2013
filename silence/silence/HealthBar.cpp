#include "HealthBar.h"
#include <SFML\Graphics.hpp>


HealthBar::HealthBar()
{
	mShape.setFillColor(sf::Color::Red);
	mShape.setSize(sf::Vector2f(50,500));
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
	newPos.x = mWindow->getView().getCenter().x + 700;
	newPos.y = mWindow->getView().getCenter().y - 300;

	float healtPercentage = 1/health;
	sf::Vector2f newSize;
	newSize.x = mShape.getSize().x;
	newSize.y = 500 - (500*healtPercentage);

	mShape.setPosition(newPos);
	mShape.setSize(newSize);
}

void HealthBar::render()
{
	mWindow->renderToCanvas(mShape, 5);
}