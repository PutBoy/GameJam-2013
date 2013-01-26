#include "WindowManager.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window\Event.hpp>

WindowManager::WindowManager(){
	mWindow = new sf::RenderWindow(sf::VideoMode(1600,900), "HeartBeater", sf::Style::Default);
	mWindow->setVerticalSyncEnabled(true);
}

WindowManager::~WindowManager(){}

WindowManager* WindowManager::getInstance(){
	static WindowManager instance;
	return &instance;
}

/*	Call this in any order and the sprites are garuanteed to be
 *	to rendered in order of the layers.
 */

void WindowManager::renderToCanvas(sf::Drawable& drawable, int layer)
{
	layers[layer].push_back(&drawable);
}

/*	This renders all the layers in the canvas, then clears.
 *	
 */
void WindowManager::renderCanvas()
{
	for (auto layer = layers.begin(); layer != layers.end(); ++layer)
	{
		for (int i = 0; i < (*layer).second.size(); ++i)
		{
			mWindow->draw(*layer->second[i]);
		}
	}
	layers.clear();
}

void WindowManager::flip()
{
	mWindow->display();
}

void WindowManager::clear()
{
	mWindow->clear();
}

bool WindowManager::isOpen()
{
	return mWindow->isOpen();
}

void WindowManager::pollEvents()
{
	sf::Event ev;
	while(mWindow->pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			mWindow->close();
	}
}
	
void WindowManager::setView(const sf::View& view)
{
	mWindow->setView(view);
}

const sf::View& WindowManager::getView()
{
	return mWindow->getView();
}
