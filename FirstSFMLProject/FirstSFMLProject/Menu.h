#ifndef _MENU_H_
#define _MENU_H_


#include "SFML\Graphics.hpp"
#include "StateController.h"



class Menu
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u size1;
	float ratiox;
	float ratioy;
public:

	Menu(int w, int h);
	~Menu()
	{

	}
	void Init();
	void Update(float time);
	void Draw(sf::RenderWindow& window);


};
#endif