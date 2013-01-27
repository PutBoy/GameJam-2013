#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H
#include <SFML\Audio.hpp>
#include <string>
#include <map>

class MusicManager
{
public:
	static MusicManager* getInstance();
	sf::Sound& loadSound(std::string key, std::string file);
	void playSound(std::string key);
	void stopSound(std::string key);
	void pauseSound(std::string key);
	bool isThisPlaying(std::string key);
private:
	MusicManager(void);
	~MusicManager(void);


	typedef std::pair<std::string, sf::SoundBuffer> bufferPair;
	typedef std::pair<std::string, sf::Sound> soundPair;
	std::map<std::string, sf::SoundBuffer>mBuffers;
	std::map<std::string, sf::Sound>mSounds;
};


#endif
