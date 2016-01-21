#include "stdafx.h"
#include "MiniMap.h"


bool MiniMap::instanceFlag = false;
MiniMap* MiniMap::instance = NULL;

MiniMap* MiniMap::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new MiniMap();
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}
void MiniMap::Init(int w, int h)
{

	//view = sf::View(sf::Vector2f(w/2, h / 2), sf::Vector2f(w * 2, h * 2)); //map that centres on player
	staticView = sf::View(sf::FloatRect(0, 0, w*3, h*3));

	//view.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
	staticView.setViewport(sf::FloatRect(0.67f, 0.04f, .30f, 0.2250f));

}
sf::View MiniMap::getView()
{
	return view;
}
void MiniMap::setView(sf::View v)
{
	view = v;
}
void MiniMap::setViewPosition(sf::Vector2f pos)
{
	view.setCenter(pos);
}
sf::View MiniMap::getStaticView()
{
	return staticView;
}