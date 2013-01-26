#include "MapTile.h"

MapTile::MapTile(sf::Vector2i spriteSheetPos, bool collidable)
	:mSpriteSheetPos(spriteSheetPos)
	,mCollidable(collidable)
{
}