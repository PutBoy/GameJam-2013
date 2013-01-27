#include "ResourceManager.h"
#include "Animation.h"

Animation::Animation(const std::string& stringName, int frameTime, int frames):
	mFrameTime(frameTime),
	mFrames(frames),
	mCurrentFrame(0),
	mLoopAmounts(0)
	
{
	
	ResourceManager* resource = ResourceManager::getInstance();

	mSprite = sf::Sprite(resource->getTexture(stringName));
	sf::IntRect textureRect(0, 0,	resource->getTexture(stringName).getSize().x/mFrames,
									resource->getTexture(stringName).getSize().y);

	mSprite.setTextureRect(textureRect);
}

Animation::~Animation(){

}

void Animation::update(){
	//nästa frame
	if(mFrameTimer.getElapsedTime().asMilliseconds() > mFrameTime){

		mFrameTimer.restart();
		mCurrentFrame++;

		// slut på animation
		if(mCurrentFrame >= mFrames){
			mCurrentFrame = 0;
			mLoopAmounts++;
		}

		sf::IntRect currentRect = mSprite.getTextureRect();
		// currentFrame(1,2,3,4...) * width
		currentRect.left = currentRect.width * mCurrentFrame;

		mSprite.setTextureRect(currentRect);
	}
}

void Animation::setPosition(sf::Vector2f& pos){
	mSprite.setPosition(pos);
}

const sf::Sprite& Animation::getSprite() const{
	return mSprite;
}

sf::Sprite& Animation::getSprite(){
	return mSprite;
}
