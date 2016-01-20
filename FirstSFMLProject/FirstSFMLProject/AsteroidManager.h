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

	void Init(int w, int h);
	void Update(float time);
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
	int max_Obstacles = 10;

};

#endif