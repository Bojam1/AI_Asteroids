#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include "SFML\Graphics.hpp"
#include "Pvector.h"
#include "Player.h"
#include <list>

class Asteroids
{
public:
	Asteroids(sf::Vector2f pos);
	~Asteroids()
	{
		cout << "Deleteing Asteroid" << endl;
	}
	bool IsColliding(Player* p);
	bool IsAlive();
	void Update(float time);
	void Draw(sf::RenderWindow& window);
	void WrapAroundScreen();
	sf::Vector2f Normalise(sf::Vector2f vec);
private:
	float m_speed = 350;
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