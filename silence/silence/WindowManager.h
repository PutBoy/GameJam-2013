#ifndef WINDOWMANAGER
#define WINDOWMANAGER

#include <map>
#include <SFML\Graphics.hpp>
#include <vector>

namespace sf
{
	class RenderWindow;
	class View;
};



class WindowManager{
public:
	static WindowManager* getInstance();

	void setView(const sf::View& view);
	const sf::View& getView();

	void setDefaultView();

	bool isOpen();
	void pollEvents();
	
	void renderToCanvas(sf::Drawable& drawable, int layer);
	void renderCanvas();

	void flip();
	void clear();
private:
	~WindowManager();
	sf::RenderWindow* mWindow;
	WindowManager();
	WindowManager& operator=(const WindowManager);
	WindowManager(const WindowManager&);

	typedef std::pair<int, std::vector<sf::Drawable*>> layerPair; 
	std::map<int, std::vector<sf::Drawable*>> layers;
};


#endif