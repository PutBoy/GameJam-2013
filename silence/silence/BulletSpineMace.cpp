#include "BulletSpineMace.h"


BulletSpineMace::BulletSpineMace(sf::Vector2f mpos, Entity* ent):
Bullet(mpos,ent)


{
	mTimer.restart();

}


BulletSpineMace::~BulletSpineMace()
{
}


void BulletSpineMace::update(){

	if(mTimer.getElapsedTime().asSeconds() > 1){
		kill();
	}
}

void BulletSpineMace::render(){
	Bullet::render();
}

void BulletSpineMace::ResolveCollision(Entity* entity){
	if(entity->isID("Enemy")){
		Enemy* enemy = dynamic_cast<Enemy*>(entity);
		if(enemy){
			enemy->doDamage(5);
		}
	}
}

sf::FloatRect BulletSpineMace::getColBox(){
	return Bullet::getColBox();

}
