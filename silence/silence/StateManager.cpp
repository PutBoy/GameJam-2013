#include "StateManager.h"
#include "State.h"


StateManager::StateManager()
	:msElapsed(0.f)
	,msUpdateRate(10.f)
{
	clock.restart();
}

StateManager::~StateManager()
{
	while (!mStack.empty())
	{
		delete mStack.top();
		mStack.pop();
	}
}

void StateManager::add(State* state){
	mStack.push(state);
}

void StateManager::update(){
	if(mStack.top()->isAlive() == true){

		//I R so clever herp derp
		for (msElapsed += clock.restart().asMilliseconds(); msElapsed > msUpdateRate; msElapsed -= msUpdateRate)
		{
			mStack.top()->update();
		}
		
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
