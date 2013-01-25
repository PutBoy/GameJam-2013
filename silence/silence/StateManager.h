#ifndef INCLUDED_STATEMANAGER
#define INCLUDED_STATEMANAGER

#include <stack>
class state;

class StateManager{
public:
	void add(State* s);
	void update();
	void render();

	static StateManager* getInstance();

private:
	typedef std::stack <State*> StateStack;
	StateStack mStack;

	~StateManager();
	StateManager();
	StateManager& operator=(const StateManager);
	StateManager(const StateManager&);
};

#endif