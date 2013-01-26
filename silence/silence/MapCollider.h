#ifndef MAPCOLLIDER_H
#define MAPCOLLIDER_H

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Rect.hpp>

class Map;

class MapCollider
{
public:
	MapCollider(Map* map);

	sf::Vector2f tryMove(sf::Vector2f position, sf::Vector2f velocity, sf::IntRect collisionBox);
private:
	static const unsigned int tileSize = 64;
	sf::Vector2i getTileFromPosition(sf::Vector2f position);
	sf::FloatRect getRectFromTile(size_t x, size_t y);

	Map* mMap;
};

#endif