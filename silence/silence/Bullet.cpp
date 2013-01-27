#include "Bullet.h"

Bullet::Bullet(sf::Vector2f mpos, Entity* ent):
	Entity(mpos),
	mEnt(ent)

{


}
	
Entity* Bullet::getEntity(){
	return mEnt;
}