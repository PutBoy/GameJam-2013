#ifndef INCLUDED_SPINEMACEPICKUP
#define INCLUDED_SPINEMACEPICKUP

#include "Pickup.h"

class SpineMace;
class Entity;

class SpineMacePickup : public Pickup{
public:

	SpineMacePickup(sf::Vector2f startPos, MapCollider m);
	~SpineMacePickup(void);
	void update();
	void render();
	sf::FloatRect getColBox();
	void ResolveCollision(Entity* entity);
private:
	Animation mAnimation;

};


#endif