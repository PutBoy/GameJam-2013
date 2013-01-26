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
	
private:

	MapGenerator mMapGenerator;
	ResourceManager* mResources;
};

#endif