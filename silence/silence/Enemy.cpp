#include "Enemy.h"


Enemy::Enemy(sf::Vector2f spawnPos): Entity(spawnPos)
{}
Enemy::~Enemy(void)
{
}


sf::Vector2f Enemy::getRandomMove()
{
	sf::Vector2f move;
	move.x = (rand()%4)-2;
	move.y = (rand()%4)-2;

	return move;
}

void Enemy::ResolveCollision(Entity* entity)
{}