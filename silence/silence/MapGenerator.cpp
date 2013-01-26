#include "MapGenerator.h"
#include "Map.h"
#include <exception>
#include <cmath>
#include <ctime>
#include <sstream>
#include "ResourceManager.h"

MapGenerator::MapGenerator(size_t w, size_t h)
	:mMap(w, h)
{
	std::stringstream ss;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			ss << "maptiles_" << i << "_" << j;
			ResourceManager::getInstance()->loadTexture(ss.str(), "map_collection_png.png", sf::IntRect(i * 64, j * 64, 64, 64));
			ss.str("");
		}
	}
	generateNew(w, h);
}

Map& MapGenerator::getMap()
{
	return mMap;
}

void MapGenerator::generateNew(size_t w, size_t h)
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	for (size_t x = 0; x < mMap.getWidth(); ++x)
	{
		for (size_t y = 0; y < mMap.getHeight(); ++y)
		{
			mMap[x][y].setSprite(0, sf::Vector2i(1, 4));
		}
	}

	for (int i = 0; i < 20; i++)
	{
		placeHut(std::rand() % mMap.getWidth(), std::rand() % mMap.getHeight());
	}

	for (int i = 0; i < 20; i++)
	{
		placeTree(std::rand() % mMap.getWidth(), std::rand() % mMap.getHeight());
	}
}

void MapGenerator::placeHut(int x, int y)
{

	if (isClear(sf::IntRect(x - 1, y - 1, 3, 3)))
	{
		for (int i = 0; i < 3; i++)
		{
			
			for (int j = 0; j < 1; j++)
			{
				int tileX = i - 1 + x;
				int tileY = j - 1 + y;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setSprite(2, sf::Vector2i(i, j));
					mMap[tileX][tileY].setCollidable(false);
					mMap[tileX][tileY].setOccupied(true);
				}
			}
			

			for (int j = 1; j < 3; j++)
			{
				int tileX = i - 1 + x;
				int tileY = j - 1 + y;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setSprite(1, sf::Vector2i(i, j));
					mMap[tileX][tileY].setCollidable(true);
					mMap[tileX][tileY].setOccupied(true);
				}
			}
		}
	}
}

void MapGenerator::placeTree(int x, int y)
{
	if (isClear(sf::IntRect(x, y, 2, 2)))
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int tileX = i + x;
				int tileY = j + y;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setSprite(1, sf::Vector2i(i + 3, j));
					mMap[tileX][tileY].setCollidable(true);
					mMap[tileX][tileY].setOccupied(true);
				}
			}
		}
	}
}

bool MapGenerator::isClear(const sf::IntRect& rect)
{
	for (int i = rect.left; i < rect.left + rect.width; i++)
	{
		for (int j = rect.top; j < rect.top + rect.height; j++)
		{

			if (i >= 0 && i < mMap.getWidth() &&
				j >= 0 && j < mMap.getHeight())
			{
				if (mMap[i][j].getOccupied() == true)
					return false;

			}
		}
	}

	return true;
}