#include "MapGenerator.h"
#include "Map.h"

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

	placeHut(5, 3);
}

void MapGenerator::placeHut(size_t x, size_t y)
{
	mMap[x - 1][y - 1] = MapTile(sf::Vector2i(0, 0), true);
	mMap[x ][y - 1] = MapTile(sf::Vector2i(1, 0), true);
	mMap[x + 1][y - 1] = MapTile(sf::Vector2i(2, 0), true);

	mMap[x - 1][y ] = MapTile(sf::Vector2i(0, 1), true);
	mMap[x ][y ] = MapTile(sf::Vector2i(1, 1), true);
	mMap[x + 1][y ] = MapTile(sf::Vector2i(2, 1), true);

	mMap[x - 1][y + 1] = MapTile(sf::Vector2i(0, 2), true);
	mMap[x ][y + 1] = MapTile(sf::Vector2i(1, 2), true);
	mMap[x + 1][y + 1] = MapTile(sf::Vector2i(2, 2), true);

}

void placeTree(size_t x, size_t y)
{

}
