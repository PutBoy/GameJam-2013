#ifndef CAMERA_H
#define CAMERA_H

#include <SFML\Graphics\View.hpp>

class Entity;

class Camera
{
public:
	Camera(Entity* obj, int freeRoam = 200);
	~Camera(void);
	sf::View& getView();
	void update();
private:
	sf::View mCamera;
	int mFreeRoam;
	Entity* mObj;	//Follow this! 
	float mDelay;
};

#endif