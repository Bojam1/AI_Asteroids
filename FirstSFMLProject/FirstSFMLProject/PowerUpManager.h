#ifndef POWERUPMANAGER_H
#define POWERUPMANAGER_H

#include "PowerUp.h"
#include "Player.h"
#include <list>
using namespace std;

class PowerUpManager
{
public:
	~PowerUpManager()
	{
		instanceFlag = false;
		for each(PowerUp* p in *powerUps)
		{
			delete p;
		}
		delete powerUps;
	}

	static PowerUpManager* GetInstance();

	void Init();
	void Update(float time, Player* p);
	void Draw(sf::RenderWindow& window);
	void AddPowerUp();

private:
	static bool instanceFlag;
	static PowerUpManager* instance;

	PowerUpManager()
	{
		powerUps = new list<PowerUp*>();
	}
	sf::Texture texture;
	list<PowerUp*>* powerUps;
	int max_PowerUps = 10;

};

#endif