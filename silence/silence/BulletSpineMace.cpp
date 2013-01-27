#include "BulletSpineMace.h"


BulletSpineMace::BulletSpineMace(sf::Vector2f mpos, std::shared_ptr<Entity> ent):
	Bullet(mpos,ent)
{
	mTimer.restart();
}

void BulletSpineMace::update(){
	if(mTimer.getElapsedTime().asSeconds() > 0.1f){
		kill();
	}
}

void BulletSpineMace::render(){
	Bullet::render();
}

void BulletSpineMace::ResolveCollision(std::shared_ptr<Entity> entity){
	if (isDead())
		return;
	if(entity->isID("Enemy"))
	{
		std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(entity);
		if(enemy){
			enemy->doDamage(70);
			kill();
		}
	}
}

sf::FloatRect BulletSpineMace::getColBox(){
	return sf::FloatRect(getPos().x - 128, getPos().y - 128, 256, 256); 

}
