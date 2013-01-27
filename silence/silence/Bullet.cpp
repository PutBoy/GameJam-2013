#include "Bullet.h"

Bullet::Bullet(sf::Vector2f mpos, std::shared_ptr<Entity> ent):
	Entity(mpos),
	mEnt(ent)

{


}
	
std::shared_ptr<Entity> Bullet::getEntity(){
	return mEnt;
}