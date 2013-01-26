#ifndef MAPTILE_H
#define MAPTILE_H

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics.hpp>
#include <string>
#include <array>

class MapTile
{
public:
	MapTile();

	bool getCollibable() const {return mCollidable;};
	sf::Sprite& getSprite(size_t layer) {return mSprites[layer];};
	const sf::Sprite& getSprite(size_t layer) const {return mSprites[layer];};
	
	void setCollidabe(bool collidable) {mCollidable = collidable;};
	void setSprite(size_t layer, const sf::Vector2i& spriteSheedPos); 

	void setOccupied(bool occupied) {mOccupied = occupied;};
	bool getOccupied() {return mOccupied;};
private:
	std::array<sf::Sprite, 3U> mSprites;
	bool mCollidable;
	bool mOccupied;
};

#endif