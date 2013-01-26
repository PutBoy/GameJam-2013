#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "Map.h"

class MapGenerator
{
public:
	MapGenerator(size_t w, size_t h);

	Map* getMap();
	void generateNew(size_t w, size_t h);
private:
	void placeHut(size_t x, size_t y);
	void placeTree(size_t x, size_t y);

	Map mMap;
};

#endif