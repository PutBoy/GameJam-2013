#ifndef CAMERA_H
#define CAMERA_H

#include <SFML\Graphics\View.hpp>

class Entity;

class Camera
{
public:
	Camera(std::shared_ptr<Entity> obj, int freeRoam = 200);
	~Camera(void);
	sf::View& getView();
	void update();
private:
	sf::View mCamera;
	int mFreeRoam;
	std::shared_ptr<Entity> mObj;	//Follow this! 
	float mDelay;
};

#endif