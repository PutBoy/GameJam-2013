#include "MapTile.h"

MapTile::MapTile(sf::Vector2i spriteSheetPos, bool collidable)
	:mSpriteSheetPos(spriteSheetPos)
	,mCollidable(collidable)
{
}

MapTile::MapTile()
	:mSpriteSheetPos(0, 0)
	,mCollidable(0)
{
}