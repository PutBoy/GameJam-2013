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
	if (newPos.y - collisionBox.width / 2 < 0)
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
				int diffX = newPos.x - (tileBox.left + tileBox.width / 2);
				int diffY = newPos.y - (tileBox.top + tileBox.height / 2);
				
				diffX = diffX / (collisionBox.width / 2 + tileBox.width / 2);
				diffY = diffY / (collisionBox.height / 2 + tileBox.height / 2);

				if(std::abs(diffY) > std::abs(diffX))
				{
					if(diffY > 0)
					{
						newPos.y = tileBox.top - collisionBox.height / 2;
						collisionBox.top = newPos.y - collisionBox.height / 2;
					}
					else
					{
						newPos.y = tileBox.top + tileBox.height + collisionBox.height / 2;
						collisionBox.top = newPos.y - collisionBox.height / 2;
					}

				}
				else
				{
					if(diffY > 0)
					{
						newPos.x = tileBox.left - collisionBox.height / 2;
						collisionBox.left = newPos.y - collisionBox.height / 2;
					}
					else
					{
						newPos.x = tileBox.left + tileBox.width + collisionBox.width / 2;
						collisionBox.left = newPos.x - collisionBox.width / 2;
					}

				}
			}
		}
	}

	
	return newPos;
}