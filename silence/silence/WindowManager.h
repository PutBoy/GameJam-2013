#ifndef WINDOWMANAGER
#define WINDOWMANAGER
#include <SFML\Graphics\RenderWindow.hpp>

class WindowManager{
public:
	static WindowManager* getInstance();
	sf::RenderWindow* getWindow();
private:
	~WindowManager();
	sf::RenderWindow* mWindow;
	WindowManager();
	WindowManager& operator=(const WindowManager);
	WindowManager(const WindowManager&);
};


#endif