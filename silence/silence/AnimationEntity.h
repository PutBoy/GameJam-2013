#ifndef ANIMATIONENTITY_H
#define ANIMATIONENTITY_H

#include "Entity.h"

#include "Animation.h"
#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\System\Vector2.hpp>

class AnimationEntity : public Entity
{
public:
	AnimationEntity(sf::Vector2f pos, const std::string& s, int frameTime, int frames);
	void update();
	virtual void render();
	virtual sf::FloatRect getColBox() {return sf::FloatRect(0.f,0.f,0.f,0.f);};
	void ResolveCollision(std::shared_ptr<Entity>) {};

private:
	Animation mAnimation;
};
#endif