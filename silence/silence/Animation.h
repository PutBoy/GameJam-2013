#ifndef INCLUDED_ANIMATION
#define INCLUDED_ANIMATION

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "ImageManager.h"

class ResourceManager

class Animation
{
public:
	Animation(const std::string& s, int frameTick, int nrFrames);
	~Animation();

	void update();
	void setPosition(sf::Vector2f& pos);
	const sf::Sprite& getSprite() const;

private:
	sf::Clock d_frameTimer;		// Used for timing the frame switch
	
	int d_frameTick;
	int d_nrFrames;
	int d_currentFrame;

	sf::Sprite d_sprite;
};

#endif
