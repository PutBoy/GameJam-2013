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
	
	sf::Vector2f tryMove(sf::Vector2f position, sf::Vector2f velo, sf::IntRect collisionRect);


private:
	sf::FloatRect Map::getRectFromTile(size_t x, size_t y);

	MapGenerator mMapGenerator;
	ResourceManager* mResources;
};

#endif