#include <iostream>
#include <list>

using namespace std;

#ifndef BULLETMANAGER
#define BULLETMANAGER

#include "Bullet.h"

class BulletManager
{
public:
	~BulletManager()
	{
		delete instance;
		instanceFlag = false;
		for (Bullet* b : bullets)
		{
			delete b;
		}
	}
	static BulletManager* GetInstance();

	void BulletManager::Draw(sf::RenderWindow& window);
	void BulletManager::Update(float);
	void BulletManager::AddBullet(sf::Vector2f, float);
	list<Bullet*>& BulletManager::GetListOfBullets();

private:
	BulletManager()
	{
		bullets = list<Bullet*>();
		bulletTexture.loadFromFile("missile.png");
	}
	static bool instanceFlag;
	static BulletManager* instance;
	sf::Texture bulletTexture;
	list<Bullet*> bullets;

};

#endif 