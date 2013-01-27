#ifndef INCLUDED_ANIMATION
#define INCLUDED_ANIMATION

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Rect.hpp>

class ResourceManager;

class Animation
{
public:
	Animation(const std::string& s, int frameTime, int frames);
	~Animation();

	void update();
	void setPosition(sf::Vector2f& pos);

	size_t loopAmounts() {return mLoopAmounts;};

	const sf::Sprite& getSprite() const;
	sf::Sprite& getSprite();

private:
	sf::Clock mFrameTimer;		// Used for timing the frame switch
	
	int mFrameTime;
	int mFrames;
	int mCurrentFrame;

	size_t mLoopAmounts;
	sf::Sprite mSprite;
};

#endif
