#include "Map.h"

utility::WidthElement::WidthElement(std::vector<tileType>& tiles, size_t x, size_t height)
	:mTiles(tiles)
	,mX(x)
	,mHeight(height)
{
}

tileType& utility::WidthElement::operator[](size_t index)
{
	int ind = mHeight * mX + index;
	return mTiles[mHeight * mX + index];
}

utility::ConstWidthElement::ConstWidthElement(const std::vector<tileType>& tiles, size_t x, size_t height)
	:mTiles(tiles)
	,mX(x)
	,mHeight(height)
{
}

const tileType& utility::ConstWidthElement::operator[](size_t index) const
{
	return mTiles[mHeight * mX + index];
}

utility::WidthElement Map::operator[](size_t index)
{
	return utility::WidthElement(mTiles, index, mHeight);
}

const utility::ConstWidthElement Map::operator[](size_t index) const
{
	return utility::ConstWidthElement(mTiles, index, mHeight);
}

Map::Map(size_t w, size_t h)
	:mWidth(w)
	,mHeight(h)
{
	
}

void Map::resize(size_t w, size_t h)
{
	mTiles.resize(w * h);
	mWidth = w;
	mHeight = h;
}
