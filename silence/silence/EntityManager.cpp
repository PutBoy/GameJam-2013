#include "EntityManager.h"


EntityManager* EntityManager::mEM = 0;


EntityManager::EntityManager()
{

	if(mEM == 0){
	mEM = new EntityManager();
	
	}
	return mEM;
}


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
	
	for(EntityVector::size_type i = 0; i < mEntities.size(); i++){
	
		mEntities[i]->update();
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

			if(mEntities[i]->isID("Enemy") ==  mEntities[j]->isID("Friend") && mEntities[i]->getColbox().intersects(mEntities[j]->getColbox()){
				mEntities[i]->setHP(mEntities[j]->getDamage());
			}

			if(mEntities[i]->isID("Friend") ==  mEntities[j]->isID("Enemy") && mEntities[i]->getColbox().intersects(mEntities[j]->getColbox()){
			mEntities[i]->setHP(mEntities[j]->getDamage());
		}
	}
}