#include "Camera.h"
#include "Entity.h"

Camera::Camera(Entity* obj): mObj(obj)
{
	mCamera.reset(sf::FloatRect(0,0,1600,900));
	mCamera.setCenter(sf::Vector2f(0,0));
}


Camera::~Camera(void)
{
}

sf::View& Camera::getView()
{
	return mCamera;
}

void Camera::update()
{
	mCamera.setCenter(mObj->getXpos()+128/2, mObj->getYpos()-128);
}