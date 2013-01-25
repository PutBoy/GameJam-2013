#include "StateManager.h"
#include "State.h"


StateManager::StateManager()
{}

void StateManager::add(State* state){
	mStack.push(state);
}

void StateManager::update(){
	if(mStack.top()->isAlive == true){
		mStack.top()->update();
	}else{
		delete mStack.top();
		mStack.pop();
	}
}

void StateManager::render(){
	//kan ändra så varje state tar hand om sin egen utritning
	mStack.top()->render();
}

StateManager* StateManager::getInstance(){
	static StateManager instance;
	return &instance;
}
