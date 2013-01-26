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
}