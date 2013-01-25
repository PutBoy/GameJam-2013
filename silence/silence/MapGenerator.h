#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H


class MapGenerator
{
public:
	MapGenerator(size_t w, size_t h);

	Map& getMap();
private:
	mMap;
};

#endif