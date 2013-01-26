#include "EntityManager.h"
#include "Entity.h"
#include "Player.h"

EntityManager::EntityManager()
{}


EntityManager::~EntityManager(){
	while(!mEntities.empty()){
		delete mEntities.back();
		mEntities.pop_back();
	}
}

void EntityManager::Add(Entity* Ent){

	mEntities.push_back(Ent);
}


void EntityManager::Draw() {

	for(EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++){
		(*i)->render();
	}
}

void EntityManager::Update(){
	Player* player;
	for(EntityVector::size_type i = 0; i <mEntities.size(); i++)
	{
			player = static_cast<Player*>(mEntities[i]);
		if(player)
			continue;
	}
	for(EntityVector::size_type i = 0; i < mEntities.size(); i++)
	{
		mEntities[i]->closeToEnemy(player);
		mEntities[i]->update();
		mEntities.push_back(mEntities[i]->getNextDrop());
	}
}

void EntityManager::AliveCheck(){

	for(EntityVector::size_type i = 0; i < mEntities.size(); i++){
	
		if(mEntities[i]->getHP() <= 0){
			mEntities[i] = mEntities.back();
			mEntities.pop_back();

		}
	}
}

void EntityManager::Collision(){
	for(EntityVector::size_type i = 0; i<mEntities.size();i++){
		for(EntityVector::size_type j = 0; j<mEntities.size();j++){

			if(mEntities[i]->isID("Enemy") ==  mEntities[j]->isID("Friend") && mEntities[i]->getColBox().intersects(mEntities[j]->getColBox())){
				mEntities[i]->setHP(mEntities[j]->getDamage());
			}

			if(mEntities[i]->isID("Friend") ==  mEntities[j]->isID("Enemy") && mEntities[i]->getColBox().intersects(mEntities[j]->getColBox())){
			mEntities[i]->setHP(mEntities[j]->getDamage());
			}
		}
	}
}

	void EntityManager::Updatedrops(){
		for(EntityVector::size_type i = 0; i < mEntities.size(); i++){
			//if(mEntities[i]
		}
	}


	EntityManager* EntityManager::getInstance(){
		static EntityManager instance;
		return &instance;
	
	}