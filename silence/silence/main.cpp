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

	while(window->isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{		
		cam.update();
		player.update();

		window->clear();


		player.render();

		map.render();

		window->renderCanvas();

		window->flip();
	}
}