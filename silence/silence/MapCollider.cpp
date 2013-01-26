#include "MapCollider.h"
#include "Map.h"

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

sf::Vector2f MapCollider::tryMove(sf::Vector2f position, sf::Vector2f velocity, sf::IntRect collisionBox)
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
	
		}
	}

	/*
	if(other->IsID("Box"))
	{
		boxCollided = true;

		int diffX = GetX() - other->GetX();
		int diffY = GetY() - other->GetY();

		if(std::abs(diffY) > std::abs(diffX))
		{
			if(diffY > 0)
			{
				SetY(other->GetY() + (GetSizeY() + other->GetSizeY()) / 2);

				if (mVelocityY < 0)
					mVelocityY = 0;
			}
			else
			{
				SetY(other->GetY() - (GetSizeY() + other->GetSizeY()) / 2);

				if (mVelocityY > 0)
					mVelocityY = 0;
			}

		}
		else
		{
			if(diffX > 0)
			{
				SetX(other->GetX() + (GetSizeX() + other->GetSizeX()) / 2 + 2);

				if (mVelocityX < 0)
					mVelocityX = 0;
			}
			else
			{
				SetX(other->GetX() - (GetSizeX() + other->GetSizeX()) / 2 - 2);

				if (mVelocityX > 0)
					mVelocityX = 0;
			}
		}
	}
	*/
	
	return newPos;
}