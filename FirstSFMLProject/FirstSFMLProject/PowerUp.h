#ifndef POWERUP_H
#define POWERUP_H

#include "SFML\Graphics.hpp"
#include "Pvector.h"
#include "Player.h"
#include <list>

class PowerUp
{
public:
	PowerUp();
	~PowerUp()
	{
		cout << "Deleteing PowerUp" << endl;
	}
	bool IsColliding(Player* p);
	bool IsAlive();
	void Update(float time);
	void Draw(sf::RenderWindow& window);
	sf::Sprite GetSprite();
private:
	float m_speed = 50;
	sf::Sprite sprite;
	sf::Vector2f m_position;
	sf::Vector2f m_dir;
	sf::Vector2f m_rotation;
	float m_radius;
	int noOfHits;
	bool isAlive;
	sf::Texture m_texture;
};


#endif