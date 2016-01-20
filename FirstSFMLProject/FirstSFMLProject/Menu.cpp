#include "stdafx.h"
#include "Menu.h"

Menu::Menu(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	if (!texture.loadFromFile("MenuBg.jpg"))
	{

	}
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0, 0));
	sprite.setScale(sf::Vector2f(1, 1));

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