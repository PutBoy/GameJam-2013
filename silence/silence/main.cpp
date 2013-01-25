#include <SFML\Graphics.hpp>

#include "Map.h"


int main()
{
	Map map;

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