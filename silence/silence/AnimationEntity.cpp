#include "AnimationEntity.h"
#include "WindowManager.h"

AnimationEntity::AnimationEntity(sf::Vector2f pos, const std::string& s, int frameTime, int frames)
	:Entity(pos)
	,mAnimation(s, frameTime, frames) 
{

}

void AnimationEntity::update()
{
	mAnimation.update();
	if (mAnimation.loopAmounts() == 1)
		kill();
}

void AnimationEntity::render()
{
	mAnimation.getSprite().setPosition(getXpos(), getYpos());
	WindowManager::getInstance()->renderToCanvas(mAnimation.getSprite(), 4);
}