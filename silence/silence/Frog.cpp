#include "Frog.h"
#include "ResourceManager.h"


Frog::Frog(sf::Vector2f spawnPos, MapCollider map): Enemy(spawnPos), mMap(map)
{
	ResourceManager* r = ResourceManager::getInstance();
	r->loadTexture("FrogRigth", "frog-sprite.png",sf::IntRect(0,0,1280,128));
	mRigth = new Animation("FrogRigth",150,10);



	mCurrentAnim = mRigth;
	mWindow = WindowManager::getInstance();

	mCollisionBox.height = 64;
	mCollisionBox.width = 96;
	mCollisionBox.left = mPos.x - mCollisionBox.width / 2;
	mCollisionBox.top = mPos.y - mCollisionBox.height / 2;
	closeToMyEnemy = false;
}


Frog::~Frog(void)
{
}

void Frog::update()
{

	sf::Vector2f move(0,0);
	if(closeToMyEnemy)
	{
		move.x -= directionToMyEnemy.x*2;
		move.y -= directionToMyEnemy.y*2;
	}

	mPos += move;
	mCollisionBox.left = mPos.x - mCollisionBox.width / 2;
	mCollisionBox.top = mPos.y - mCollisionBox.height / 2;

	move = mMap.tryMove(mPos, move, mCollisionBox);
	mPos = move;
}

void Frog::render()
{
	mCurrentAnim->setPosition(mPos - sf::Vector2f(64, 96));
	mWindow->renderToCanvas(mCurrentAnim->getSprite(), 0);
}

float Frog::getHP()
{
	return 0.f;
}

std::string Frog::isID(std::string ID)
{
	return "Frog";
}

float Frog::getDamage()
{
	return 0.f;
}

void Frog::setHP(float damage)
{

}

sf::FloatRect Frog::getColBox()
{
	return mCollisionBox;
}
