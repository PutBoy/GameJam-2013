#ifndef INCLUDED_KNUCKLESPICKUP
#define INCLUDED_KNUCKLESPICKUP

#include "Pickup.h"
#include "Animation.h"

class Knuckles;
class Entity;

class KnucklesPickup : public Pickup{
public:

	KnucklesPickup(sf::Vector2f startPos);
	~KnucklesPickup(void);
	void update();
	void render();
	sf::FloatRect getColBox();
	void ResolveCollision(std::shared_ptr<Entity> entity);
private:
	Animation mAnimation;

};


#endif