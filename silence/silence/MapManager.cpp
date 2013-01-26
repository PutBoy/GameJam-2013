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
	int bufferdepth[3] = {-2 , -1 , 2};

	Map& map = mMapGenerator.getMap();
	WindowManager* window = WindowManager::getInstance();

		
	int leftTile = (window->getView().getCenter().x - window->getView().getSize().x / 2) / 64;
	int rightTile = (window->getView().getCenter().x + window->getView().getSize().x / 2) / 64 + 1;

	int topTile = (window->getView().getCenter().y - window->getView().getSize().y / 2) / 64;
	int bottomTile = (window->getView().getCenter().y + window->getView().getSize().y / 2) / 64 + 1;

	if (leftTile < 0)
		leftTile = 0;

	if (topTile < 0)
		topTile = 0;

	if (map.getHeight() < bottomTile)
		bottomTile = map.getHeight() - 1;

	if (map.getWidth() < rightTile)
		rightTile = map.getWidth() - 1;


	for (size_t x = leftTile; x < rightTile; ++x)
	{
		for (size_t y = topTile; y < bottomTile; ++y)
		{
			for (int z = 0; z < 3; ++z)
			{
				if (map[x][y].getSprite(z).getTexture() != nullptr)
				{
					map[x][y].getSprite(z).setPosition(x * 64, y * 64);
					window->renderToCanvas(map[x][y].getSprite(z), bufferdepth[z]);
				}
			}
		}
	}
}

