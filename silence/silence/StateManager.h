#ifndef INCLUDED_STATEMANAGER
#define INCLUDED_STATEMANAGER

#include <stack>
#include <SFML\System\Clock.hpp>

class State;

class StateManager{
public:
	void add(State* state);
	void update();
	void render();

	static StateManager* getInstance();

private:
	sf::Clock clock;
	float msElapsed;
	const float msUpdateRate;

	typedef std::stack <State*> StateStack;
	StateStack mStack;

	~StateManager();
	StateManager();
	StateManager& operator=(const StateManager&);
	StateManager(const StateManager&);
};

#endif