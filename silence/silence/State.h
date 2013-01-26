#ifndef INCLUDED_STATE
#define INCLUDED_STATE

class StateManager;

class State{
public:
	State();
	virtual ~State(){};
	virtual bool isAlive()=0;
	virtual void update()=0;
	virtual void render()=0;
protected:
	const StateManager& getStateManager() const {return *SM;};
	StateManager& getStateManager() {return *SM;};

private:
	StateManager* SM;
};

#endif