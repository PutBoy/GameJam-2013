#include "MapTile.h"
#include "ResourceManager.h"
#include <sstream>

MapTile::MapTile()
	:mCollidable(0)
{
}

void MapTile::setSprite(size_t index, const sf::Vector2i& spriteSheetPos)
{
	if (index >= mSprites.size())
		return;

	std::stringstream ss;

	ss << "maptiles_" << spriteSheetPos.x << "_" << spriteSheetPos.y;
	mSprites[index] = sf::Sprite(ResourceManager::getInstance()->getTexture(ss.str()));
}
