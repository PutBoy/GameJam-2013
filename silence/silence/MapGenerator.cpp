#include "MapGenerator.h"
#include "Map.h"
#include <exception>

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
	for (size_t x = 0; x < mMap.getWidth(); ++x)
	{
		for (size_t y = 0; y < mMap.getHeight(); ++y)
		{
			mMap[x][y] = MapTile(sf::Vector2i(0, 4), false);
		}
	}

	placeHut(0, 3);
	placeHut(9, 3);
	placeTree(1, 7);
	placeTree(4, 7);
}

void MapGenerator::placeHut(int x, int y)
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

void MapGenerator::placeTree(int x, int y)
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
