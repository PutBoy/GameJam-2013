#ifndef INCLUDE_BULLETSPINEMACE
#define INCLUDE_BULLETSPINEMACE
#include <SFML\System\Clock.hpp>
#include "Bullet.h"
#include "Enemy.h"
#include "Weapon.h"
#include <SFML\System\Clock.hpp>

class BulletSpineMace : public Bullet

{
public:
	BulletSpineMace(sf::Vector2f mpos, std::shared_ptr<Entity> ent);
	void update();
	void render();

	
	void ResolveCollision(std::shared_ptr<Entity> entity);
	sf::FloatRect getColBox();


private:
	sf::Vector2f mPos;

	sf::Clock mTimer;

};

#endif
