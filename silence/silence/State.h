#ifndef INCLUDED_STATE
#define INCLUDED_STATE

class StateManager;

class State{
public:
	virtual ~State(){};
	virtual bool isAlive()=0;
	virtual void update()=0;
	virtual void render()=0;
private:
	StateManager* SM;
};

#endif