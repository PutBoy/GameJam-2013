#include "MapManager.h"
#include "Map.h"

#include "ResourceManager.h"
#include <sstream>
#include "WindowManager.h"

MapManager::MapManager()
	:mMapGenerator(50, 50)
	,mResources(ResourceManager::getInstance())
{
	
}

void MapManager::render()
{
	Map& map = mMapGenerator.getMap();
	sf::RenderWindow* window = WindowManager::getInstance()->getWindow();

			
	for (size_t x = 0; x < map.getWidth(); ++x)
	{
		for (size_t y = 0; y < map.getHeight(); ++y)
		{

			sf::Sprite sprite(map[x][y].getSprite());

			sprite.setPosition(x * 64, y * 64);
			window->draw(sprite);

		}
	}
}