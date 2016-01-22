#include "stdafx.h"
#include "Menu.h"

Menu::Menu(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	if (!texture.loadFromFile("MenuBg.jpg"))
	{

	}
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0, 0));
	size1 = texture.getSize();
	ratiox = (float)SCREEN_WIDTH / (float)size1.x;
	ratioy = (float)SCREEN_HEIGHT / (int)size1.y;
	sprite.setScale(sf::Vector2f(ratiox, ratioy));

	



}

void Menu::Init()
{

}
void Menu::Update(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		StateController::GetInstance()->SetState(StateController::GetInstance()->PLAY);
	}
}
void Menu::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}