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

	if (pos.x >= 400 && pos.x <= 2000)
		camView.setCenter(pos.x, camView.getCenter().y);
	else if (pos.x < 400)
		camView.setCenter(400, camView.getCenter().y);
	else if (pos.x > 2000)
		camView.setCenter(2000, camView.getCenter().y);

	if (pos.y >= 300 && pos.y <= 1500)
		camView.setCenter(camView.getCenter().x, pos.y);
	else if (pos.y < 300)
		camView.setCenter(camView.getCenter().x, 300);
	else if (pos.y > 1500)
		camView.setCenter(camView.getCenter().x, 1500);
}