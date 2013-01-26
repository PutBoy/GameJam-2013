#include "MapCollider.h"
#include "Map.h"
#include <cmath>

MapCollider::MapCollider(Map* map)
	:mMap(map)
{

}

sf::Vector2i MapCollider::getTileFromPosition(sf::Vector2f position)
{
	sf::Vector2i tilePosition;
	tilePosition.x = (static_cast<int>(position.x) / (static_cast<int>(mMap->getWidth()) + tileSize / 2));
	tilePosition.y = (static_cast<int>(position.y) / (static_cast<int>(mMap->getHeight()) + tileSize / 2));

	return tilePosition;
}

sf::FloatRect MapCollider::getRectFromTile(size_t x, size_t y)
{
	return sf::FloatRect(x * tileSize, y * tileSize, tileSize, tileSize);
}

sf::Vector2f MapCollider::tryMove(sf::Vector2f position, sf::Vector2f velocity, sf::FloatRect collisionBox)
{
	sf::Vector2f newPos = position;
	
	//check if box is outside of the screen.
	if (newPos.x  - collisionBox.width / 2 < 0)
	{ 
		newPos.x = collisionBox.width / 2;
	}
	if (newPos.y - collisionBox.height / 2 < 0)
	{
		newPos.y = collisionBox.height / 2;
	}
	if (newPos.x + collisionBox.width / 2 > mMap->getWidth() * tileSize)
	{
		newPos.x = (mMap->getWidth() * tileSize) - collisionBox.width / 2;
	}
	if (newPos.y + collisionBox.height / 2 > mMap->getHeight() * tileSize)
	{
 		newPos.y = (mMap->getHeight() * tileSize) - collisionBox.height / 2;
	}

	collisionBox.left = newPos.x - collisionBox.width / 2;
	collisionBox.top = newPos.y - collisionBox.height / 2;

	for (int iterY = (newPos.y - collisionBox.height / 2) / tileSize; iterY < (newPos.y + collisionBox.height / 2) / tileSize; iterY++)
	{
		for (int iterX = (newPos.x- collisionBox.width / 2) / tileSize; iterX < (newPos.x + collisionBox.width / 2) / tileSize; iterX++)
		{
			//If tile is outside of the collisionMap, ignore that tile
			if (iterX < 0 || iterX >= mMap->getWidth() ||
				iterY < 0 || iterY >= mMap->getHeight())
				continue;

			if ((*mMap)[iterX][iterY].getCollibable() == false)
				continue;

			sf::FloatRect tileBox = getRectFromTile(iterX, iterY);
			sf::FloatRect interRect;

			if (collisionBox.intersects(tileBox, interRect))
			{
				sf::Vector2f distance = distanceRectToRect(tileBox, collisionBox);
				sf::Vector2f major = getMajorVector(distance);

				//this tile is an internal edge if the next tile is also collidable.
				//if this tile is NOT such a tile, then handle collision.
				int nextTileX = iterX + major.x;
				int nextTileY = iterY + major.y;
				if ((*mMap)[nextTileX][nextTileY].getCollibable() == false)
				{
					//do not be tempted to use interRect, it won't move the position excactly right.
					if (major.x < -.5)
					{
						newPos.x = tileBox.left - collisionBox.width / 2;
						collisionBox.left = newPos.x - collisionBox.width / 2;
					}
					else if (major.x > .5)
					{
						newPos.x = tileBox.left + tileBox.width + collisionBox.width / 2;
						collisionBox.left = newPos.x - collisionBox.width / 2;
					}
					else if (major.y < -.5)
					{
						newPos.y = tileBox.top - collisionBox.height / 2;
						collisionBox.top = newPos.y - collisionBox.height / 2;
					}
					else if (major.y > .5)
					{
						newPos.y = tileBox.top + tileBox.height + collisionBox.height / 2;
						collisionBox.top = newPos.y - collisionBox.height / 2;
					}
				}
			
			}
		}
	}

	
	return newPos;
}

/*	This returns the difference vector between two rectangles. Sort of.
 *		Written: Sebastian Zander 13-01-18 23:21
 *	This function will not work when the difference in size between the rectangles are too big.
 */
sf::Vector2f MapCollider::distanceRectToRect(sf::FloatRect r0, sf::FloatRect r1)
{
	//calculate the two centers
	sf::Vector2f c0(r0.left + r0.width / 2, r0.top + r0.height / 2);
	sf::Vector2f c1(r1.left + r1.width / 2, r1.top + r1.height / 2);
	//calculate the diffence between the two centers.
	sf::Vector2f diff = c1 - c0;

	//scale the distance to take account for the width and height of the objects. THIS IS NOT PERFECT.
	diff.x = diff.x / (r0.width / 2 + r1.width / 2);
	diff.y = diff.y / (r0.height / 2 + r1.height / 2);

	return diff;
}

/*	This function returns the major (unit) vector given a vector
 *		Written: Sebastian Zander 13-01-18 23:48
 */
sf::Vector2f MapCollider::getMajorVector(sf::Vector2f vec)
{
	if (std::abs(vec.x) > std::abs(vec.y))
	{
		return sf::Vector2f((vec.x < 0 ? -1.0f : 1.0f), 0.0f);
	}
	else
	{
		return sf::Vector2f(0.0f, (vec.y < 0 ? -1.0f : 1.0f));
	}
}