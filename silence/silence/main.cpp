#include <SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "WindowManager.h"
#include "Player.h"
#include "MapManager.h"
#include "Camera.h"
#include <sstream>

int main()
{
	WindowManager* window = WindowManager::getInstance();
	sf::RenderWindow* win = window->getWindow();
	ResourceManager* resources = ResourceManager::getInstance();


	std::stringstream ss;

	for (size_t x = 0; x < 5; ++x)
	{
		for (size_t y = 0; y < 5; ++y)
		{
			ss << "maptiles_" << x << "_" << y;
			resources->loadTexture(ss.str(), "map_collection_png.png", sf::IntRect(x * 64, y * 64, 64, 64) );
			ss.str("");
		}
	}


	MapManager map;


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