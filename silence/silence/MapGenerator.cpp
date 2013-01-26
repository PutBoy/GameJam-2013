#include "MapGenerator.h"
#include "Map.h"
#include <exception>
#include <cmath>
#include <ctime>

MapGenerator::MapGenerator(size_t w, size_t h)
	:mMap(w, h)
{
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
			mMap[x][y] = MapTile(sf::Vector2i(0, 4), false);
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
			for (int j = 0; j < 3; j++)
			{
				int tileX = i - 1 + x;
				int tileY = j - 1 + y;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY] = MapTile(sf::Vector2i(i, j), true);
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
					mMap[i + x][j + y] = MapTile(sf::Vector2i(i + 3, j), true);
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
				if (mMap[i][j].getCollibable() == true)
					return false;

			}
		}
	}

	return true;
}