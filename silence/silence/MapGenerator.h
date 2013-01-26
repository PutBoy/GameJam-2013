#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "Map.h"
#include <SFML\System\Vector2.hpp>

class MapGenerator
{
public:
	MapGenerator(size_t w, size_t h);

	Map& getMap();
	void generateNew(size_t w, size_t h);


private:

	void placeHut(int x, int y);
	void placeTree(int x, int y);

	bool isClear(const sf::IntRect& rect);
	Map mMap;
};

#endif