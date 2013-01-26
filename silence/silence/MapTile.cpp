#include "MapTile.h"
#include "ResourceManager.h"
#include <sstream>

MapTile::MapTile(sf::Vector2i spriteSheetPos, bool collidable)
	:mSpriteSheetPos(spriteSheetPos)
	,mCollidable(collidable)

{
	std::stringstream ss;

	ss << "maptiles_" << spriteSheetPos.x << "_" << spriteSheetPos.y;
	mSprite = sf::Sprite(ResourceManager::getInstance()->getTexture(ss.str()));
}

MapTile::MapTile()
	:mSpriteSheetPos(0, 0)
	,mCollidable(0)
{
}