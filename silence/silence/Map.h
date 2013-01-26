 /*	Operator[] returns a utility::WidthElement object whose 
 *	operator[] in turn returns a tileType based on the indices
 *	entered. TileType is the type defined to represent a tile.
 *		Written: Sebastian Zander 13-01-18 15:39
 */


#ifndef COLLISIONMAP_H
#define COLLISIONMAP_H

#include <vector>
#include <SFML\Graphics\Rect.hpp>
#include "MapTile.h"

typedef MapTile tileType;

/*	WidthElement is used to resolve a 2d postion in a 1d vector
 *		Written: Sebastian Zander 13-01-18 15:39
 */
namespace utility
{
	class WidthElement
	{
	public:
		WidthElement(std::vector<tileType>& mTiles, size_t x, size_t height);

		tileType& operator[](size_t index);
		
	private:
		std::vector<tileType>& mTiles;
		size_t mX;
		size_t mHeight;
	};

	class ConstWidthElement
	{
	public:
		ConstWidthElement(const std::vector<tileType>& mTiles, size_t x, size_t height);

		const tileType& operator[](size_t index) const;
		
	private:
		const std::vector<tileType>& mTiles;
		size_t mX;
		size_t mHeight;
	};

};

class Map
{
public:
	Map(size_t w, size_t h);

	void resize(size_t w, size_t h);

	utility::WidthElement operator[](size_t index);
	const utility::ConstWidthElement operator[](size_t index) const;
	
	size_t getWidth() const {return mWidth;};
	size_t getHeight() const {return mHeight;};

private:
	std::vector<tileType> mTiles;
	size_t mWidth;
	size_t mHeight;
};

#endif