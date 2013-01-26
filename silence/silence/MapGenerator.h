#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "Map.h"
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Rect.hpp>

class MapGenerator
{
public:
	MapGenerator(size_t w, size_t h);

	Map& getMap();
	void generateNew(size_t w, size_t h);


private:
	enum Direction {NONE = -1, UP, DOWN, LEFT, RIGHT};
	enum OppositeDirection {OPP_NONE = NONE, OPP_UP = DOWN, OPP_DOWN = UP, OPP_LEFT = RIGHT, OPP_RIGHT = LEFT};


	bool placeWalkWay(const sf::Vector2i& start, const sf::Vector2i stop);
	void placeRoadTile(const sf::Vector2i& walkWayPos, Direction direction, Direction prevDirection);

	void placeHut(int x, int y);
	void placeTree(int x, int y);

	bool isClear(const sf::IntRect& rect);
	Map mMap;
};

#endif