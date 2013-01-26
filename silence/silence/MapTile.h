#ifndef MAPTILE_H
#define MAPTILE_H

#include <SFML\System\Vector2.hpp>

class MapTile
{
public:
	MapTile(sf::Vector2i spriteSheetPos, bool coolidable);
	bool getCollibable() const {return mCollidable;};
	const sf::Vector2i& getSheetPosition() const {return mSpriteSheetPos;};
private:
	sf::Vector2i mSpriteSheetPos;
	bool mCollidable;
};

#endif