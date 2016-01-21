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

	desktop = sf::VideoMode::getDesktopMode();
	window_height = desktop.height;
	window_width = desktop.width;
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

	if (pos.x >= window_width / 2 && pos.x <= 1680)
		camView.setCenter(pos.x, camView.getCenter().y);
	else if (pos.x < window_width / 2)
		camView.setCenter(window_width / 2, camView.getCenter().y);
	else if (pos.x > 1680)
		camView.setCenter(1680, camView.getCenter().y);

	if (pos.y >= window_height / 2 && pos.y <= 1350)
		camView.setCenter(camView.getCenter().x, pos.y);
	else if (pos.y < window_height / 2)
		camView.setCenter(camView.getCenter().x, window_height / 2);
	else if (pos.y > 1350)
		camView.setCenter(camView.getCenter().x, 1350);
}