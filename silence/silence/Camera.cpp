#include "Camera.h"
#include "Entity.h"

Camera::Camera(Entity* obj, float delay): mObj(obj), mDelay(delay)
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
	if(mObj->getXpos() >= mCamera.getCenter().x + mDelay)
		mCamera.setCenter(mObj->getXpos(), mObj->getYpos()-mDelay);
	else if(mObj->getXpos() <= mCamera.getCenter().x - mDelay)
		mCamera.setCenter(mObj->getXpos(), mObj->getYpos()+mDelay);

	if(mObj->getYpos() >= mCamera.getCenter().y + mDelay)
		mCamera.setCenter(mObj->getYpos(), mObj->getYpos()-mDelay);
	else if(mObj->getYpos() <= mCamera.getCenter().y - mDelay)
		mCamera.setCenter(mObj->getYpos(), mObj->getYpos()+mDelay);
}