#ifndef CAMERA_H
#define CAMERA_H

#include <SFML\Graphics\View.hpp>
class Entity;

class Camera
{
public:
	Camera(Entity* obj);
	~Camera(void);
	sf::View& getView();
	void update();
private:
	sf::View mCamera;
	Entity* mObj;	//Follow this! 
	float mDelay;
};

#endif