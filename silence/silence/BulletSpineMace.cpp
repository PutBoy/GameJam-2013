#include "BulletSpineMace.h"
#include "SpineMace.h"
#include "Animation.h"
#include "ResourceManager.h"
#include "BulletSpineMace.h"
#include "Player.h"
#include <SFML\System\Vector2.hpp>
#include "MusicManager.h"
#include "BulletKnuckles.h"

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
	sf::Vector2f dir = (std::dynamic_pointer_cast<Player>(getEntity()))->getDir();

	if(dir.x >= 1){
		return sf::FloatRect(getPos().x - 128, getPos().y - 128, 200, 200);
	}else if(dir.x <= -1){
		return sf::FloatRect(getPos().x - 128, getPos().y - 128, 200, 200);
	}else if(dir.y >= 1){
		return sf::FloatRect(getPos().x - 128, getPos().y + 128, 200, 200);
	}else if(dir.y <= -1){
		return sf::FloatRect(getPos().x - 128, getPos().y - 128, 200, 200);
	}
	else
	{
		return sf::FloatRect(getPos().x - 128, getPos().y - 128, 256, 256); 
	}

}
