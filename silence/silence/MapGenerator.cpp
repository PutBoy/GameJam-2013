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
	mMap.resize(w, h);

	std::srand(static_cast<unsigned int>(std::time(0)));
	std::vector<sf::Vector2i> groundSprites;
	groundSprites.push_back(sf::Vector2i(1, 4));


	//place ground
	for (size_t x = 0; x < mMap.getWidth(); ++x)
	{
		for (size_t y = 0; y < mMap.getHeight(); ++y)
		{
			mMap[x][y].setSprite(0, groundSprites[std::rand() % groundSprites.size()]);
		}
	}

		
	while(!placeWalkWay(sf::Vector2i(0, 0), sf::Vector2i(w - 1, h - 1)))
	{
		std::srand(static_cast<unsigned int>(std::clock()));
	}
	
	for (int i = 0; i < w + h / 2; i++)
	{
		placeStone(std::rand() % mMap.getWidth(), std::rand() % mMap.getHeight());
	}

	for (int i = 0; i < w + h / 2; i++)
	{
		placeHut(std::rand() % mMap.getWidth(), std::rand() % mMap.getHeight());
	}

	for (int i = 0; i < w + h / 2; i++)
	{
		placeTree(std::rand() % mMap.getWidth(), std::rand() % mMap.getHeight());
	}
}

void MapGenerator::placeStone(int x, int y)
{
	int width = std::rand() % 3 + 3;
	int height = std::rand() % 3 + 3;


	sf::IntRect stoneRect(x - width / 2, y - height / 2, width, height );
	
	if (width % 2 == 0)
		x-=1;
	if (height % 2 == 0)
		y-=1;
	
	if (isClear(stoneRect))
	{
		//first occupy wall street
		for (int i = stoneRect.left; i < stoneRect.left + stoneRect.width; i++)
		{
			for (int j = stoneRect.top; j < stoneRect.top + stoneRect.height; j++)
			{
				int tileX = i;
				int tileY = j;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setOccupied(true);
				}
			}
		}

		//then fill in the middle
		for (int i = stoneRect.left + 1; i < stoneRect.left + stoneRect.width - 1; i++)
		{
			for (int j = stoneRect.top + 1; j < stoneRect.top + stoneRect.height - 1; j++)
			{
				int tileX = i;
				int tileY = j;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setSprite(1, sf::Vector2i(3, 6));
					mMap[tileX][tileY].setCollidable(true);
				}
			}
		}

		//then fill in the fuckers!
		for (int i = stoneRect.left + 1; i < stoneRect.left + stoneRect.width - 1; i++)
		{
			int tileX = i;
			int tileY = stoneRect.top;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(1, sf::Vector2i(3, 5));
				mMap[tileX][tileY].setCollidable(false);
			}
		}

		for (int i = stoneRect.left + 1; i < stoneRect.left + stoneRect.width - 1; i++)
		{
			int tileX = i;
			int tileY = stoneRect.top + stoneRect.height - 1;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(1, sf::Vector2i(3, 7));
				mMap[tileX][tileY].setCollidable(false);
			}
		}

		for (int i = stoneRect.top + 1; i < stoneRect.top + stoneRect.height - 1; i++)
		{
			int tileX = stoneRect.left;
			int tileY = i;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(1, sf::Vector2i(4, 7));
				mMap[tileX][tileY].setCollidable(false);
			}
		}

		for (int i = stoneRect.top + 1; i < stoneRect.top + stoneRect.height - 1; i++)
		{
			int tileX = stoneRect.left + stoneRect.width - 1;
			int tileY = i;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(1, sf::Vector2i(4, 6));
				mMap[tileX][tileY].setCollidable(false);
			}
		}
	}
}

void MapGenerator::placeHut(int x, int y)
{
	int width = std::rand() % 3 + 3;
	int height = std::rand() % 3 + 3;


	sf::IntRect hutRect(x - width / 2, y - height / 2, width, height );
	
	if (width % 2 == 0)
		x-=1;
	if (height % 2 == 0)
		y-=1;
	
	if (isClear(hutRect))
	{
		//first make all tiles occupied
		for (int i = hutRect.left; i < hutRect.left + hutRect.width; i++)
		{
			for (int j = hutRect.top; j < hutRect.top + hutRect.height; j++)
			{
				int tileX = i;
				int tileY = j;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setOccupied(true);
				}
			}
		}

		//then place corners:
		if (hutRect.left >= 0 && hutRect.left < mMap.getWidth() &&
			hutRect.top >= 0 && hutRect.top < mMap.getHeight())
		{
			mMap[hutRect.left][hutRect.top].setSprite(2, sf::Vector2i(0, 0));
			mMap[hutRect.left][hutRect.top].setCollidable(false);
		}

		if (hutRect.left + hutRect.width - 1 >= 0 && hutRect.left + hutRect.width - 1 < mMap.getWidth() &&
			hutRect.top >= 0 && hutRect.top < mMap.getHeight())
		{
			mMap[hutRect.left + hutRect.width - 1][hutRect.top].setSprite(2, sf::Vector2i(2, 0));
			mMap[hutRect.left + hutRect.width - 1][hutRect.top].setCollidable(false);
		}

		if (hutRect.left >= 0 && hutRect.left < mMap.getWidth() &&
			hutRect.top + hutRect.height - 1 >= 0 && hutRect.top + hutRect.height - 1 < mMap.getHeight())
		{
			mMap[hutRect.left][hutRect.top + hutRect.height - 1].setSprite(1, sf::Vector2i(0, 2));
			mMap[hutRect.left][hutRect.top + hutRect.height - 1].setCollidable(true);
		}

		if (hutRect.left + hutRect.width - 1 >= 0 && hutRect.left + hutRect.width - 1 < mMap.getWidth() &&
			hutRect.top + hutRect.height - 1 >= 0 && hutRect.top + hutRect.height - 1 < mMap.getHeight())
		{
			mMap[hutRect.left + hutRect.width - 1][hutRect.top + hutRect.height - 1].setSprite(1, sf::Vector2i(2, 2));
			mMap[hutRect.left + hutRect.width - 1][hutRect.top + hutRect.height - 1].setCollidable(true);
		}
		
		//place roof!
		for (int i = hutRect.left + 1; i < hutRect.left + hutRect.width - 1; i++)
		{
			for (int j = hutRect.top + 1; j < hutRect.top + hutRect.height - 1; j++)
			{
				int tileX = i;
				int tileY = j;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setSprite(2, sf::Vector2i(0, 3));
					mMap[tileX][tileY].setCollidable(true);
				}
			}
		}
		
		//then place chimney!
		if (x >= 0 && x < mMap.getWidth() &&
			y >= 0 && y < mMap.getHeight())
		{
			mMap[x][y].setSprite(2, sf::Vector2i(1, 1));
			mMap[x][y].setCollidable(true);
		}

		
		//NOW PLACE WALLS! OVER AND OUT MOTHERFAKKARS!
		for (int i = hutRect.left + 1; i < hutRect.left + hutRect.width - 1; i++)
		{
			int tileX = i;
			int tileY = hutRect.top;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(2, sf::Vector2i(1, 0));
				mMap[tileX][tileY].setCollidable(false);
			}
		}

		for (int i = hutRect.left + 1; i < hutRect.left + hutRect.width - 1; i++)
		{
			int tileX = i;
			int tileY = hutRect.top + hutRect.height - 1;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(1, sf::Vector2i(1, 2));
				mMap[tileX][tileY].setCollidable(true);
			}
		}

		for (int i = hutRect.top + 1; i < hutRect.top + hutRect.height - 1; i++)
		{
			int tileX = hutRect.left;
			int tileY = i;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(1, sf::Vector2i(0, 1));
				mMap[tileX][tileY].setCollidable(true);
			}
		}

		for (int i = hutRect.top + 1; i < hutRect.top + hutRect.height - 1; i++)
		{
			int tileX = hutRect.left + hutRect.width - 1;
			int tileY = i;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(1, sf::Vector2i(2, 1));
				mMap[tileX][tileY].setCollidable(true);
			}
		}

		//BUT FIRST PLACE DA FUCKING DOOR!
		if (x >= 0 && x < mMap.getWidth() &&
			hutRect.top + hutRect.height - 1 >= 0 && hutRect.top + hutRect.height - 1 < mMap.getHeight())
		{
			mMap[x][hutRect.top + hutRect.height - 1].setSprite(1, sf::Vector2i(0, 4));
			mMap[x][hutRect.top + hutRect.height - 1].setCollidable(true);
		}

	}
}

void MapGenerator::placeTree(int x, int y)
{
	int width = std::rand() % 4 + 2;
	int height = std::rand() % 4 + 3;


	sf::IntRect treeRect(x - 1, y - 1, width, height );
	
	if (isClear(treeRect))
	{
		//first make all tiles occupied:
		for (int i = treeRect.left; i < treeRect.left + treeRect.width; i++)
		{
			for (int j = treeRect.top; j < treeRect.top + treeRect.height; j++)
			{
				int tileX = i;
				int tileY = j;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setOccupied(true);
				}
			}
		}

		//then place corners:
		if (treeRect.left >= 0 && treeRect.left < mMap.getWidth() &&
			treeRect.top >= 0 && treeRect.top < mMap.getHeight())
		{
			mMap[treeRect.left][treeRect.top].setSprite(2, sf::Vector2i(3, 0));
			mMap[treeRect.left][treeRect.top].setCollidable(false);
		}

		if (treeRect.left + treeRect.width - 1 >= 0 && treeRect.left + treeRect.width - 1 < mMap.getWidth() &&
			treeRect.top >= 0 && treeRect.top < mMap.getHeight())
		{
			mMap[treeRect.left + treeRect.width - 1][treeRect.top].setSprite(2, sf::Vector2i(4, 0));
			mMap[treeRect.left + treeRect.width - 1][treeRect.top].setCollidable(false);
		}

		if (treeRect.left >= 0 && treeRect.left < mMap.getWidth() &&
			treeRect.top + treeRect.height - 1 >= 0 && treeRect.top + treeRect.height - 1 < mMap.getHeight())
		{
			mMap[treeRect.left][treeRect.top + treeRect.height - 1].setSprite(2, sf::Vector2i(3, 1));
			mMap[treeRect.left][treeRect.top + treeRect.height - 1].setCollidable(false);
		}

		if (treeRect.left + treeRect.width - 1 >= 0 && treeRect.left + treeRect.width - 1 < mMap.getWidth() &&
			treeRect.top + treeRect.height - 1 >= 0 && treeRect.top + treeRect.height - 1 < mMap.getHeight())
		{
			mMap[treeRect.left + treeRect.width - 1][treeRect.top + treeRect.height - 1].setSprite(2, sf::Vector2i(4, 1));
			mMap[treeRect.left + treeRect.width - 1][treeRect.top + treeRect.height - 1].setCollidable(false);
		}

		//place mid leaves! THERE ARE NONE!
		for (int i = treeRect.left + 1; i < treeRect.left + treeRect.width - 1; i++)
		{
			for (int j = treeRect.top + 1; j < treeRect.top + treeRect.height - 1; j++)
			{
				int tileX = i;
				int tileY = j;

				if (tileX >= 0 && tileX < mMap.getWidth() &&
					tileY >= 0 && tileY < mMap.getHeight())
				{
					mMap[tileX][tileY].setSprite(2, sf::Vector2i(4, 5));
					mMap[tileX][tileY].setCollidable(false);
				}
			}
		}

		//NOW PLACE EDGES! OVER AND OTHER MOTHERFATHERS!
		for (int i = treeRect.left + 1; i < treeRect.left + treeRect.width - 1; i++)
		{
			int tileX = i;
			int tileY = treeRect.top;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(2, sf::Vector2i(3, 2));
				mMap[tileX][tileY].setCollidable(false);
			}
		}
		
		for (int i = treeRect.left + 1; i < treeRect.left + treeRect.width - 1; i++)
		{
			int tileX = i;
			int tileY = treeRect.top + treeRect.height - 1;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(2, sf::Vector2i(4, 3));
				mMap[tileX][tileY].setCollidable(false);
			}
		}
		
		for (int i = treeRect.top + 1; i < treeRect.top + treeRect.height - 1; i++)
		{
			int tileX = treeRect.left;
			int tileY = i;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(2, sf::Vector2i(4, 2));
				mMap[tileX][tileY].setCollidable(false);
			}
		}

		for (int i = treeRect.top + 1; i < treeRect.top + treeRect.height - 1; i++)
		{
			int tileX = treeRect.left + treeRect.width - 1;
			int tileY = i;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(2, sf::Vector2i(4, 4));
				mMap[tileX][tileY].setCollidable(false);
			}
		}
		
		//BUT BEFORE WE LEAVE: PLACE DA FUCKING TRUNK SON!
		for (int i = treeRect.left + 1; i < treeRect.left + treeRect.width - 1; i++)
		{
			int tileX = i;
			int tileY = treeRect.top + treeRect.height;

			if (tileX >= 0 && tileX < mMap.getWidth() &&
				tileY >= 0 && tileY < mMap.getHeight())
			{
				mMap[tileX][tileY].setSprite(1, sf::Vector2i(2, 3));
				mMap[tileX][tileY].setCollidable(true);
			}
		}

		//EDGES
		if (treeRect.left >= 0 && treeRect.left < mMap.getWidth() &&
			treeRect.top + treeRect.height >= 0 && treeRect.top + treeRect.height < mMap.getHeight())
		{
			mMap[treeRect.left][treeRect.top + treeRect.height].setSprite(1, sf::Vector2i(1, 3));
			mMap[treeRect.left][treeRect.top + treeRect.height].setCollidable(true);
		}

		if (treeRect.left + treeRect.width - 1 >= 0 && treeRect.left + treeRect.width - 1 < mMap.getWidth() &&
			treeRect.top + treeRect.height >= 0 && treeRect.top + treeRect.height < mMap.getHeight())
		{
			mMap[treeRect.left + treeRect.width - 1][treeRect.top + treeRect.height].setSprite(1, sf::Vector2i(3, 3));
			mMap[treeRect.left + treeRect.width - 1][treeRect.top + treeRect.height].setCollidable(true);
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
	std::vector<sf::Vector2i> roadSprites;
	roadSprites.push_back(sf::Vector2i(0, 5));
	roadSprites.push_back(sf::Vector2i(0, 7));
	roadSprites.push_back(sf::Vector2i(1, 6));
	roadSprites.push_back(sf::Vector2i(2, 5));
	roadSprites.push_back(sf::Vector2i(2, 7));

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
			mMap[walkWayPos.x * 4 + x][walkWayPos.y * 4 + y].setSprite(1, roadSprites[std::rand() % roadSprites.size()]);
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
	for (int i = rect.left; i < rect.left + rect.width + 1; i++)
	{
		for (int j = rect.top; j < rect.top + rect.height + 1; j++)
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