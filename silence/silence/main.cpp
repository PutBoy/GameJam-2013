#include <SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "WindowManager.h"
#include "Player.h"
#include "MapManager.h"
#include "Camera.h"

int main()
{
	WindowManager* window = WindowManager::getInstance();
	sf::RenderWindow* win = window->getWindow();
	
	MapManager map;

	ResourceManager* resources = ResourceManager::getInstance();


	Player player(sf::Vector2f(200,200));
	Camera cam(&player);

	while(win->isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		sf::Event event;
		while(win->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win->close();
		}
		
		cam.update();
		player.update();

		win->clear();

		//win->setView(cam.getView());
	
		map.render();
		player.render();


		win->display();
	}
}