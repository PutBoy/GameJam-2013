#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "MapGenerator.h"
#include "ResourceManager.h"
#include <SFML/System/Vector2.hpp>

class MapManager
{
public:
	MapManager();
	void render();
	Map* getMap() const {return mMap;};
private:
	Map* mMap;
	MapGenerator mMapGenerator;
	ResourceManager* mResources;
};

#endif