#include <SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "WindowManager.h"
#include "Player.h"
#include "Map.h"


int main()
{
	WindowManager* window = WindowManager::getInstance();
	sf::RenderWindow* win = window->getWindow();
	
	Map map(50,50);
	ResourceManager* resources = ResourceManager::getInstance();


	Player player(sf::Vector2f(200,200));


	while(win->isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		sf::Event event;
		while(win->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win->close();
		}
		win->clear();
		
		player.update();
		player.render();



		win->display();
	}
}