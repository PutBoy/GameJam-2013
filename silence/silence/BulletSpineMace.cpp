#include "BulletSpineMace.h"


BulletSpineMace::BulletSpineMace(sf::Vector2f mpos, std::shared_ptr<Entity> ent):
	Bullet(mpos,ent)
{
	mTimer.restart();
}

void BulletSpineMace::update(){
	if(mTimer.getElapsedTime().asSeconds() > 1){
		kill();
	}
}

void BulletSpineMace::render(){
	Bullet::render();
}

void BulletSpineMace::ResolveCollision(std::shared_ptr<Entity> entity){
	if(entity->isID("Enemy")){
		std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(entity);
		if(enemy){
			enemy->doDamage(9001);
			kill();
		}
	}
}

sf::FloatRect BulletSpineMace::getColBox(){
	return sf::FloatRect(getPos().x - 64, getPos().y - 64, 128, 128); 

}
