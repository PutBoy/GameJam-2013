#include "MusicManager.h"
#include <cassert>




MusicManager::MusicManager(void)
{
}


MusicManager::~MusicManager(void)
{
}


MusicManager* MusicManager::getInstance()
{
	static MusicManager MusicInstance;
	return &MusicInstance;
}

sf::Sound& MusicManager::loadSound(std::string key, std::string file)
{
	if (mBuffers.count(file) == 0)
	{
		sf::SoundBuffer buffer;
		buffer.loadFromFile(file);
		mBuffers.insert(bufferPair(file, buffer));
	}

	if (mSounds.count(key) == 0)
	{
		sf::Sound sound;
		sound.setBuffer(mBuffers.at(file));
		mSounds.insert(soundPair(key,sound));
	}

	return mSounds.at(key);
}

void MusicManager::playSound(std::string key)
{
	assert(mSounds.count(key) != 0);
	mSounds.at(key).play();
}

void MusicManager::stopSound(std::string key)
{
	assert(mSounds.count(key) != 0);
	mSounds.at(key).stop();
}

void MusicManager::pauseSound(std::string key)
{
	assert(mSounds.count(key) != 0);
	mSounds.at(key).pause();
}

bool MusicManager::isThisPlaying(std::string key)
{
	assert(mSounds.count(key) != 0);
	if(mSounds.at(key).getStatus() == sf::SoundSource::Status::Playing)
		return true;
	else
		return false;
}