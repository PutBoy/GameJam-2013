#include "MapGenerator.h"
#include "Map.h"
#include <exception>
#include <cmath>
#include <ctime>
#include <sstream>
#include "ResourceManager.h"
#include <vector>

MapGenerator::MapGenerator(size_t w, size_t h)
	:mMap(w, h)
{
	std::stringstream ss;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			ss << "maptiles_" << i << "_" << j;
			ResourceManager::getInstance()->loadTexture(ss.str(), "map_collection_png.png", sf::IntRect(i * 64, j * 64, 64, 64));
			ss.str("");
		}
	}
	generateNew(w, h);
}

Map& MapGenerator::getMap()
{
	return mMap;
}

void MapGenerator::generateNew(size_t w, size_t h)
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	for (size_t x = 0; x < mMap.getWidth(); ++x)
	{
		for (size_t y = 0; y < mMap.getHeight(); ++y)
		{
			mMap[x][y].setSprite(0, sf::Vector2i(1, 4));
		}
	}

	while(!placeWalkWay(sf::Vector2i(0, 0), sf::Vector2i(w - 1, h - 1)))
	{

	}

	for (int i = 0; i < 20; i++)
	{
		placeHut(std::rand() % mMap.getWidth(), std::rand() % mMap.getHeight());
	}

	for (int i = 0; i < 20; i++)
	{
		placeTree(std::rand() % mMap.getWidth(), std::rand() % mMap.getHeight());
	}
}

void MapGenerator::placeHut(int x, int y)
{

	if (isClear(sf::IntRect(x - 1, y - 1, 3, 3)))
	{
		for (int i = 0; i < 3; i++)
		{
			
			for (int j = 0; j < 1; j++)
			{
				int tileX = i - 1 + x;
				int tileY = j - 1 + y;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setSprite(2, sf::Vector2i(i, j));
					mMap[tileX][tileY].setCollidable(false);
					mMap[tileX][tileY].setOccupied(true);
				}
			}
			

			for (int j = 1; j < 3; j++)
			{
				int tileX = i - 1 + x;
				int tileY = j - 1 + y;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setSprite(1, sf::Vector2i(i, j));
					mMap[tileX][tileY].setCollidable(true);
					mMap[tileX][tileY].setOccupied(true);
				}
			}
		}
	}
}

void MapGenerator::placeTree(int x, int y)
{
	if (isClear(sf::IntRect(x, y, 2, 2)))
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int tileX = i + x;
				int tileY = j + y;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setSprite(1, sf::Vector2i(i + 3, j));
					mMap[tileX][tileY].setCollidable(true);
					mMap[tileX][tileY].setOccupied(true);
				}
			}
		}
	}
}

bool MapGenerator::placeWalkWay(const sf::Vector2i& start, const sf::Vector2i stop)
{		

	std::array<sf::Vector2i, 4U> directionVectors;

	directionVectors[UP] = sf::Vector2i(0, -1);
	directionVectors[DOWN] = sf::Vector2i(0, 1);
	directionVectors[LEFT] = sf::Vector2i(-1, 0);
	directionVectors[RIGHT] = sf::Vector2i(1, 0);

	sf::Vector2i startWalk = start / 4;
	sf::Vector2i stopWalk = stop / 4;
	sf::Vector2i currentPos = startWalk;

	size_t h = mMap.getHeight() / 4;
	size_t w = mMap.getWidth() / 4;
	std::vector<Direction> walkWay(h * w);
	std::vector<Direction> prevWalk(h * w);

	for (int i = 0; i < walkWay.size(); i++)
	{
		walkWay[i] = NONE;
		prevWalk[i] = NONE;
	}
		
	//My first lamda :3
	auto getIndex = [&] (size_t x, size_t y) -> int {
		size_t h = mMap.getHeight() / 4;
		return h * x + y;
	};
	
	auto randDir = [] () -> int {return std::rand() % 4;};
	
	auto inRange = [=] (int x, int y) -> bool {return x >= 0 && x < w && y >= 0  && y < h;};
		
	auto getMajor = [=] (sf::Vector2i pos) -> sf::Vector2i 
	{	
		sf::Vector2i vec = stop - pos;
		if (std::abs(vec.x) > std::abs(vec.y))
		{
			return sf::Vector2i((vec.x < 0 ? -1: 1), 0);
		}
		else
		{
			return sf::Vector2i(0, (vec.y < 0 ? -1 : 1));
		}
	};
	
		
	Direction currentDir = NONE;

	bool done = false;
	while (!done)
	{
		std::vector<Direction> possibleDirs;
		for (int i = 0; i < 4; i++)
		{

			int nextX = (currentPos + directionVectors[i]).x;
			int nextY = (currentPos + directionVectors[i]).y;

			if (!inRange(nextX , nextY))
				continue;

			if (walkWay[getIndex(nextX, nextY)] == NONE)
			{
				sf::Vector2i major = getMajor(currentPos);
				Direction dir = static_cast<Direction>(i);
				if (dir == currentDir)
				{
					possibleDirs.push_back(static_cast<Direction>(i));
					possibleDirs.push_back(static_cast<Direction>(i));
				}
				if (directionVectors[static_cast<Direction>(i)] == major)
				{
					possibleDirs.push_back(static_cast<Direction>(i));
					possibleDirs.push_back(static_cast<Direction>(i));
					possibleDirs.push_back(static_cast<Direction>(i));
				}
				if(directionVectors[static_cast<Direction>(i)] != -major)
				{
					possibleDirs.push_back(static_cast<Direction>(i));
				}

				possibleDirs.push_back(static_cast<Direction>(i));
			}
		}

		if (possibleDirs.size() == 0)
			break;

		prevWalk[getIndex(currentPos.x, currentPos.y)] = currentDir;
		currentDir = possibleDirs[std::rand() % possibleDirs.size()];
		walkWay[getIndex(currentPos.x, currentPos.y)] = currentDir;

		currentPos += directionVectors[currentDir];

		if (currentPos == stopWalk)
		{
			done = true;
			walkWay[getIndex(currentPos.x, currentPos.y)] = currentDir;
			prevWalk[getIndex(currentPos.x, currentPos.y)] = walkWay[getIndex(currentPos.x - directionVectors[currentDir].x, currentPos.y - directionVectors[currentDir].y)];
		}
	}

	if (!done)
		return false;

	for (size_t x = 0; x < w; ++x)
	{
		for (size_t y = 0; y < h; ++y)
		{

			placeRoadTile(sf::Vector2i(x,y), walkWay[getIndex(x, y)], prevWalk[getIndex(x, y)]);

		}
	}
}

void MapGenerator::placeRoadTile(const sf::Vector2i& walkWayPos, Direction direction, Direction prevDirection)
{
	if (direction == NONE)
		return;

	//set blocks to occupied first
	for (size_t x = walkWayPos.x * 4; x < walkWayPos.x * 4 + 4; ++x)
	{
		for (size_t y = walkWayPos.y * 4; y < walkWayPos.y * 4 + 4; ++y)
		{

				mMap[x][y].setOccupied(true);
		}
	}

	//set mid blocks
	for (size_t x = 1; x < 3; ++x)
	{
		for (size_t y = 1; y < 3; ++y)
		{
			//pick a random sprite for walkway here
			mMap[walkWayPos.x * 4 + x][walkWayPos.y * 4 + y].setSprite(1, sf::Vector2i(1, 6));
		}
	}

	for (size_t i = 1; i < 3; ++i)
	{
		mMap[walkWayPos.x * 4][walkWayPos.y * 4 + i].setSprite(1, sf::Vector2i(0, 6));
		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + i].setSprite(1, sf::Vector2i(2, 6));
	}
	
	for (size_t i = 1; i < 3; ++i)
	{
		mMap[walkWayPos.x * 4 + i][walkWayPos.y * 4].setSprite(1, sf::Vector2i(1, 5));
		mMap[walkWayPos.x * 4 + i][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(1, 7));

	}

	//set blocks based on next direction;

	
	if (direction == DOWN)
	{
		mMap[walkWayPos.x * 4 + 1][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(1, 6));
		mMap[walkWayPos.x * 4 + 2][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(1, 6));

		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(0, 6));
		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(2, 6));
	}

	else if (direction == UP)
	{
		mMap[walkWayPos.x * 4 + 1][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(1, 6));
		mMap[walkWayPos.x * 4 + 2][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(1, 6));

		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(0, 6));
		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(2, 6));
	}
	
	else if (direction == LEFT)
	{
		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 1].setSprite(1, sf::Vector2i(1, 6));
		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 2].setSprite(1, sf::Vector2i(1, 6));

		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(1, 5));
		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(1, 7));
	}
	
	else if (direction == RIGHT)
	{
		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 1].setSprite(1, sf::Vector2i(1, 6));
		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 2].setSprite(1, sf::Vector2i(1, 6));

		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(1, 5));
		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(1, 7));
	}
	
	
	
	if (prevDirection == UP)
	{
		mMap[walkWayPos.x * 4 + 1][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(1, 6));
		mMap[walkWayPos.x * 4 + 2][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(1, 6));

		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(0, 6));
		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(2, 6));
	}

	else if (prevDirection == DOWN)
	{
		mMap[walkWayPos.x * 4 + 1][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(1, 6));
		mMap[walkWayPos.x * 4 + 2][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(1, 6));

		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(0, 6));
		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(2, 6));
	}
	if (prevDirection == RIGHT)
	{
		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 1].setSprite(1, sf::Vector2i(1, 6));
		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 2].setSprite(1, sf::Vector2i(1, 6));

		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(1, 5));
		mMap[walkWayPos.x * 4 + 0][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(1, 7));
	}
	
	else if (prevDirection == LEFT)
	{
		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 1].setSprite(1, sf::Vector2i(1, 6));
		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 2].setSprite(1, sf::Vector2i(1, 6));

		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 0].setSprite(1, sf::Vector2i(1, 5));
		mMap[walkWayPos.x * 4 + 3][walkWayPos.y * 4 + 3].setSprite(1, sf::Vector2i(1, 7));
	}
}

bool MapGenerator::isClear(const sf::IntRect& rect)
{
	for (int i = rect.left; i < rect.left + rect.width; i++)
	{
		for (int j = rect.top; j < rect.top + rect.height; j++)
		{

			if (i >= 0 && i < mMap.getWidth() &&
				j >= 0 && j < mMap.getHeight())
			{
				if (mMap[i][j].getOccupied() == true)
					return false;

			}
		}
	}

	return true;
}