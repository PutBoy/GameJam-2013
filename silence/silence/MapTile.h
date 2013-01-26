#ifndef MAPTILE_H
#define MAPTILE_H

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics.hpp>

class MapTile
{
public:
	MapTile();
	MapTile(sf::Vector2i spriteSheetPos, bool coolidable);
	bool getCollibable() const {return mCollidable;};
	const sf::Vector2i& getSheetPosition() const {return mSpriteSheetPos;};
	const sf::Sprite& getSprite() const {return mSprite;};
private:
	sf::Sprite mSprite;
	sf::Vector2i mSpriteSheetPos;
	bool mCollidable;
};

#endif