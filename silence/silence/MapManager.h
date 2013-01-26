#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "MapGenerator.h"
#include "ResourceManager.h"

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