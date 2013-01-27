#include "Bat.h"
#include "ResourceManager.h"
#include "DeathAnimation.h"
#include <memory>
#include "Player.h"
Bat::Bat(sf::Vector2f spawnPos, MapCollider map): Enemy(spawnPos, 20), mMap(map)
	,mLeft("BatLeft",50,10), mRigth("BatRigth",50,10), mUp("BatUp",50,10), mDown("BatDown",50,10)
{
	mCurrentAnim = &mRigth;
	mWindow = WindowManager::getInstance();

	mCollisionBox.height = 64;
	mCollisionBox.width = 96;
	mCollisionBox.left = mPos.x - mCollisionBox.width / 2;
	mCollisionBox.top = mPos.y - mCollisionBox.height / 2;
	closeToMyEnemy = false;
}


Bat::~Bat(void)
{
}

void Bat::update()
{

	if (getHP() < 0.f)
	{
		Drop(std::make_shared<DeathAnimation>(mPos, 0.6));
		kill();
	}
	sf::Vector2f move(0,0);
	if(closeToMyEnemy)
	{
		move.x -= directionToMyEnemy.x*2;
		move.y -= directionToMyEnemy.y*2;
	}

	if(move.x > 0 && move.x > move.y)
		mCurrentAnim = &mRigth;//
	else if(move.x < 0 && move.x < move.y)
		mCurrentAnim = &mLeft;
	if(move.y > 0 && move.x < move.y)
		mCurrentAnim = &mDown;//
	else if(move.y < 0 && move.x > move.y)
		mCurrentAnim = &mUp;
	
	mPos += move;
	mCollisionBox.left = mPos.x - mCollisionBox.width / 2;
	mCollisionBox.top = mPos.y - mCollisionBox.height / 2;

	mCurrentAnim->update();

	move = mMap.tryMove(mPos, move, mCollisionBox);
	mPos = move;
}

void Bat::render()
{
	mCurrentAnim->setPosition(mPos - sf::Vector2f(64, 96));
	mWindow->renderToCanvas(mCurrentAnim->getSprite(), 0);
}

std::string Bat::isID(std::string ID)
{
	return "Bat";
}

float Bat::getDamage()
{
	return 0.f;
}

void Bat::setHP(float damage)
{

}

sf::FloatRect Bat::getColBox()
{
	return mCollisionBox;
}

void Bat::ResolveCollision(std::shared_ptr<Entity> entity)
{
	sf::Vector2f newPos(entity->getXpos(),entity->getYpos());
	sf::Vector2f distance = distanceRectToRect(entity->getColBox(), mCollisionBox);
	sf::Vector2f major = getMajorVector(distance);

	sf::FloatRect entbox = entity->getColBox();

	if (major.x < -.5)
	{
		newPos.x -= distance.x; //entbox.left - mCollisionBox.width / 2;
		entbox.left = mPos.x - mCollisionBox.width / 2;
	}
	else if (major.x > .5)
	{
		newPos.x -= distance.x;// entbox.left + entbox.width + mCollisionBox.width / 2;
		entbox.left = mPos.x - mCollisionBox.width / 2;
	}
	else if (major.y < -.5)
	{
		newPos.y -= distance.y;// entbox.top - mCollisionBox.height / 2;
		entbox.top = mPos.y - mCollisionBox.height / 2;
	}
	else if (major.y > .5)
	{
		newPos.y -= distance.y;// entbox.top + entbox.height + mCollisionBox.height / 2;
		entbox.top = mPos.y - mCollisionBox.height / 2;
	}
	entity->setPos(newPos);

	std::shared_ptr<Player> play = std::dynamic_pointer_cast<Player>(entity);
	if(std::dynamic_pointer_cast<Player>(entity))
		play->doDamage(0.1);

	if(std::dynamic_pointer_cast<Player>(entity));


}