#include "Camera.h"
#include "Entity.h"

Camera::Camera(std::shared_ptr<Entity> obj, int freeRoam): mObj(obj), mFreeRoam(freeRoam)
{
	mCamera.reset(sf::FloatRect(0,0,1600,900));
	mCamera.setCenter(sf::Vector2f(mObj->getXpos() + 64, mObj->getYpos() + 64));
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

	int objRelativeX = mObj->getXpos() - mCamera.getCenter().x + 64;
	int objRelativeY = mObj->getYpos() - mCamera.getCenter().y + 64;

	if (objRelativeX > mFreeRoam )
	{
		mCamera.setCenter(mCamera.getCenter().x + objRelativeX - mFreeRoam, mCamera.getCenter().y);
	}
	if (objRelativeX < -mFreeRoam )
	{
		mCamera.setCenter(mCamera.getCenter().x + objRelativeX + mFreeRoam, mCamera.getCenter().y);
	}
	if (objRelativeY > mFreeRoam )
	{
		mCamera.setCenter(mCamera.getCenter().x, mCamera.getCenter().y + objRelativeY - mFreeRoam);
	}
	if (objRelativeY < -mFreeRoam )
	{
		mCamera.setCenter(mCamera.getCenter().x, mCamera.getCenter().y + objRelativeY + mFreeRoam);
	}
}