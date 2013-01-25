#include "ResourceManager.h"
#include <cassert>

ResourceManager* ResourceManager::getInstance()
{
	static ResourceManager thisIsAResourceInstance;
	return &thisIsAResourceInstance;
}

sf::Texture& ResourceManager::loadTexture(std::string key, std::string file, sf::IntRect imageRect)
{
	if (mImages.count(file) == 0)
	{
		sf::Image image;
		image.loadFromFile(file);
		mImages.insert(imagePair(file, image));
	}

	if (mTextures.count(key) == 0)
	{
		sf::Texture texture;
		texture.loadFromImage(mImages.at(file), imageRect);
		mTextures.insert(texturePair(key,texture));
	}

	return mTextures.at(key);
}

sf::Texture& ResourceManager::getTexture(std::string key)
{
	assert(mTextures.count(key) != 0);

	return mTextures.at(key);
}
