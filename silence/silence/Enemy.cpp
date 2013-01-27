#include "Enemy.h"


Enemy::Enemy(sf::Vector2f spawnPos, float HP): Entity(spawnPos), mHP(HP)
{
	pushID("Enemy");
}
Enemy::~Enemy(void)
{
}


void Enemy::ResolveCollision(std::shared_ptr<Entity> entity)
{}

void Enemy::doDamage(float damage){
	mHP -= damage;
}