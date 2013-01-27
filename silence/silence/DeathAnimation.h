#ifndef DEATHANIMATION_H
#define DEATHANIMATION_H

#include "AnimationEntity.h"

class DeathAnimation : public AnimationEntity
{
public:
	DeathAnimation(sf::Vector2f pos, float scale):
		AnimationEntity(pos - sf::Vector2f(0, 24), "deathanimationenemy", 50, 10){
			getAnimation().getSprite().setScale(scale, scale);
			getAnimation().getSprite().setOrigin(129, 129);
		};
private:
	float mScale;
};

#endif

