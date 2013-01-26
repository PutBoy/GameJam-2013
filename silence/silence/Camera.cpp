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
	int objRelativeX = mObj->getXpos() - mCamera.getCenter().x;
	int objRelativeY = mObj->getXpos() - mCamera.getCenter().x;

	if (objRelativeX > 100 )
	{
		mCamera.setCenter(mObj->getXpos(), mObj->getYpos());
	}
	if (objRelativeX < 100 )
	{
		mCamera.setCenter(mObj->getXpos(), mObj->getYpos());
	}
	if (objRelativeY > 100 )
	{
		mCamera.setCenter(mObj->getXpos(), mObj->getYpos());
	}
	if (objRelativeY < 100 )
	{
		mCamera.setCenter(mObj->getXpos(), mObj->getYpos());
	}
}