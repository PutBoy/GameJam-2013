#include "ResourceManager.h"

Animation::Animation(const std::string& s, int fTick, int nrFrames):
	d_frameTick(fTick),
	d_nrFrames(nrFrames),
	d_currentFrame(0),
	d_sprite(ResourceManager::getInstance()->getTexture(s))
{
	
	ResourceManager::getInstance();


	sf::IntRect textureRect(0, 0,	ResourceManager::getInstance()->getTexture(s).getSize().x/d_nrFrames,
									ResourceManager::getInstance()->getTexture(s).getSize().y);

	d_sprite.setTextureRect(textureRect);
}

Animation::~Animation(){

}

void Animation::update(){
	//nästa frame
	if(d_frameTimer.getElapsedTime().asMilliseconds() > d_frameTick){

		d_frameTimer.restart();
		d_currentFrame++;

		// slut på animation
		if(d_currentFrame >= d_nrFrames){
			d_currentFrame = 0;
		}

		sf::IntRect currentRect = d_sprite.getTextureRect();
		// currentFrame(1,2,3,4...) * width
		currentRect.left = currentRect.width * d_currentFrame;

		d_sprite.setTextureRect(currentRect);
	}
}

void Animation::setPosition(sf::Vector2f& pos){
	d_sprite.setPosition(pos);
}

const sf::Sprite& Animation::getSprite() const{
	return d_sprite;
}
