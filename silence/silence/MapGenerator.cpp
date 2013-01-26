#include "MapGenerator.h"
#include "Map.h"

MapGenerator::MapGenerator(size_t w, size_t h)
	:mMap(w, h)
{
	generateNew(w, h);
}

Map* MapGenerator::getMap()
{
	return &mMap;
}

void MapGenerator::generateNew(size_t w, size_t h)
{

}

void placeHut(size_t x, size_t y)
{

}

void placeTree(size_t x, size_t y)
{

}
