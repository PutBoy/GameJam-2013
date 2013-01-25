#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML\Graphics.hpp>
#include <string>
#include <map>

class ResourceManager
{
public:

	static ResourceManager* getInstance();

	sf::Texture& loadTexture(std::string key, std::string file, sf::IntRect imageRect);
	sf::Texture& getTexture(std::string key);

private:
	ResourceManager();
	ResourceManager(const ResourceManager&) {};
	ResourceManager& operator=(const ResourceManager&) {};
	
	typedef std::pair<std::string, sf::Image> imagePair;
	typedef std::pair<std::string, sf::Texture> texturePair;

	std::map<std::string, sf::Image> mImages;
	std::map<std::string, sf::Texture> mTextures;


};

#endif