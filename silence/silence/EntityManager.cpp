#include "EntityManager.h"
#include "Entity.h"
#include "Player.h"

EntityManager::EntityManager()
{}


EntityManager::~EntityManager(){

}

void EntityManager::AddPlayer(std::shared_ptr<Entity> ent)
{
	mPlayer = ent;
	mEntities.push_back(ent);
}

void EntityManager::Add(std::shared_ptr<Entity> ent){

	mEntities.push_back(ent);
}


void EntityManager::Draw() {

	for(EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++){
		(*i)->render();
	}
}

void EntityManager::Update(){

	for(EntityVector::size_type i = 0; i < mEntities.size(); i++)
	{
		if(mEntities[i] != mPlayer)	
			mEntities[i]->closeToEnemy(mPlayer);
		mEntities[i]->update();
	}

	Updatedrops();
	
	Collision();

	AliveCheck();
}

void EntityManager::AliveCheck(){

	mGraveYard.clear();

	for(EntityVector::size_type i = 0; i < mEntities.size(); i++){
	
		if(mEntities[i]->isDead() == true){
			mGraveYard.push_back(mEntities[i]);
			mEntities[i] = mEntities.back();
			mEntities.pop_back();
			i--;
		}
	}
}

void EntityManager::Collision(){
	for(EntityVector::size_type i = 0; i<mEntities.size();i++)
	{
		for(EntityVector::size_type j = 0; j<mEntities.size();j++)
		{

			if(mEntities[i]->getColBox().intersects(mEntities[j]->getColBox()))
			{

				if (i != j)
					mEntities[j]->ResolveCollision(mEntities[i]);

			}
		}
	}
}

	void EntityManager::Updatedrops(){
		for(EntityVector::size_type i = 0; i < mEntities.size(); i++){

			std::shared_ptr<Entity> drop = mEntities[i]->getNextDrop();
			while (drop != nullptr)
			{			

				mEntities.push_back(drop);
				drop = mEntities[i]->getNextDrop();
			}
		}
	}

