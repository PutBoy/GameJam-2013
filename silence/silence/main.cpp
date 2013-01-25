#include <SFML\Graphics.hpp>
#include "ResourceManager.h"

#include "Map.h"


int main()
{
	Map map(50,50);
	ResourceManager* resources = ResourceManager::getInstance();
	resources->loadTexture("Player", "sprite.png", sf::IntRect(0, 64, 64, 64));
	
	resources->getTexture("Player");

	sf::RenderWindow window(sf::VideoMode(1600,900),"Game");

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		
		window.display();
	}
}