#include "MapManager.h"
#include "Map.h"

#include "ResourceManager.h"
#include <sstream>
#include "WindowManager.h"

MapManager::MapManager()
	:mMapGenerator(50, 50)
	,mResources(ResourceManager::getInstance())
{
	std::stringstream ss;

	for (size_t x = 0; x < 10; ++x)
	{
		for (size_t y = 0; x < 10; ++x)
		{
			ss << "maptiles_" << x << "_" << y;
			mResources->loadTexture(ss.str(), "map_collection_png.png", sf::IntRect(x * 32, y * 32, 32, 32) );
			ss.str("");
		}
	}
	
}

void MapManager::render()
{
	Map* map = mMapGenerator.getMap();
	sf::RenderWindow* window = WindowManager::getInstance()->getWindow();
	std::stringstream ss;

	for (size_t x = 0; x < map->getWidth(); ++x)
	{
		for (size_t y = 0; y < map->getHeight(); ++y)
		{
			sf::Vector2i sheetPos = (*map)[x][y].getSheetPosition();
			
			ss << "maptiles_" << sheetPos.x << "_" << sheetPos.y;
			sf::Sprite sprite(mResources->getTexture(ss.str()));
			sprite.setPosition(x * 32, y * 32);

			ss.str("");
		}
	}
}