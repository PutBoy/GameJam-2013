#ifndef DEATHANIMATION_H
#define DEATHANIMATION_H

#include "AnimationEntity.h"

class DeathAnimation : public AnimationEntity
{
	DeathAnimation(sf::Vector2f pos):
		AnimationEntity(pos, "deathanimationenemy", 100, 10){};
};

#endif

