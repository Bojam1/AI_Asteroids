#ifndef ASTEROIDMANAGER_H
#define ASTEROIDMANAGER_H

#include "Asteroids.h"
#include "Player.h"
#include <list>
using namespace std;

class AsteroidManager
{
public:
	~AsteroidManager()
	{
		instanceFlag = false;
		for each(Asteroids* e in *asteroids)
		{
			delete e;
		}
		delete asteroids;
	}

	static AsteroidManager* GetInstance();

	void Init(sf::Vector2f playerPos);
	void Update(float time, Player* p);
	void Draw(sf::RenderWindow& window);
	void AddAsteroid(sf::Vector2f playerPos);

private:
	static bool instanceFlag;
	static AsteroidManager* instance;

	AsteroidManager()
	{
		asteroids = new list<Asteroids*>();
	}
	sf::Texture texture;
	list<Asteroids*>* asteroids;
	int max_Asteroids = 10;

};

#endif