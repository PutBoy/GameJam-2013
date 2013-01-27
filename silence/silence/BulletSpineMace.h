#ifndef INCLUDE_BULLETSPINEMACE
#define INCLUDE_BULLETSPINEMACE
#include <SFML\System\Clock.hpp>
#include "Bullet.h"
#include "Enemy.h"

class BulletSpineMace : public Bullet

{
public:
	BulletSpineMace(sf::Vector2f mpos, Entity* ent);
	void update();
	void render();

	
	void ResolveCollision(Entity* entity);
	sf::FloatRect getColBox();
	~BulletSpineMace();

private:
	sf::Vector2f mPos;

	sf::Clock mTimer;

};

#endif
