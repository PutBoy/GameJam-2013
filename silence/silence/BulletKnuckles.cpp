#include "BulletKnuckles.h"


BulletKnuckles::BulletKnuckles(sf::Vector2f mpos, std::shared_ptr<Entity> ent): Bullet(mpos,ent)
{
}


void BulletKnuckles::update(){
	if(mTimer.getElapsedTime().asSeconds() > 0.1f){
		kill();
	}
}

void BulletKnuckles::render(){
	Bullet::render();
}

void BulletKnuckles::ResolveCollision(std::shared_ptr<Entity> entity){
	if (isDead())
		return;
	if(entity->isID("Enemy")){
		std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(entity);
		if(enemy){
			enemy->doDamage(9001);
			kill();
		}
	}
}

sf::FloatRect BulletKnuckles::getColBox(){
	return sf::FloatRect(getPos().x - 64, getPos().y - 64, 256, 256); 
}
