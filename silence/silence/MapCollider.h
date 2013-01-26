#ifndef MAPCOLLIDER_H
#define MAPCOLLIDER_H

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Rect.hpp>

class Map;

class MapCollider
{
public:
	MapCollider(Map* map);

	sf::Vector2f tryMove(sf::Vector2f position, sf::Vector2f velocity, sf::FloatRect collisionBox);
private:
	static const unsigned int tileSize = 64;
	sf::Vector2i getTileFromPosition(sf::Vector2f position);
	sf::FloatRect getRectFromTile(size_t x, size_t y);

	sf::Vector2f distanceRectToRect(sf::FloatRect, sf::FloatRect);
	sf::Vector2f getMajorVector(sf::Vector2f);

	Map* mMap;
};

#endif