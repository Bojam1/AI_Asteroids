#include "stdafx.h"
#include "Camera.h"


bool Camera::instanceFlag = false;
Camera* Camera::instance = NULL;

Camera* Camera::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new Camera();
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}
void Camera::Init(int w, int h)
{
	camView = sf::View(sf::FloatRect(w / 2, h / 2, w, h));
	camView.setViewport(sf::FloatRect(0, 0, 1, 1));
}
void Camera::setCentre(sf::Vector2f pos)
{

}
sf::View Camera::getView()
{
	return camView;
}
void Camera::setView(sf::View v)
{
	camView = v;
}
void Camera::setViewPosition(sf::Vector2f pos)
{
	camView.setCenter(pos);
}