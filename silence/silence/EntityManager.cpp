#include "EntityManager.h"
#include "Entity.h"
#include "Player.h"

EntityManager::EntityManager()
{}


EntityManager::~EntityManager(){
	for (size_t i = 0; i < mEntities.size(); i++)
	{
		delete mEntities[i];
	}
}

void EntityManager::AddPlayer(Entity* ent)
{
	mPlayer = ent;
	mEntities.push_back(ent);
}

void EntityManager::Add(Entity* ent){

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

}

void EntityManager::AliveCheck(){

	for(EntityVector::size_type i = 0; i < mEntities.size(); i++){
	
		//if(mEntities[i]->getHP() <= 0){
		//	mEntities[i] = mEntities.back();
		//	mEntities.pop_back();

		//}
	}
}

void EntityManager::Collision(){
	for(EntityVector::size_type i = 0; i<mEntities.size();i++){
		for(EntityVector::size_type j = 0; j<mEntities.size();j++){

			if(mEntities[i]->getColBox().intersects(mEntities[i]->getColBox()))
			{
				mEntities[j]->ResolveCollision(mEntities[i]);
			}
	}
}

	void EntityManager::Updatedrops(){
		for(EntityVector::size_type i = 0; i < mEntities.size(); i++){
			Entity* drop = mEntities[i]->getNextDrop();
			while (drop != nullptr)
			{
				mEntities.push_back(drop);
				drop = mEntities[i]->getNextDrop();
			}
		}
	}

