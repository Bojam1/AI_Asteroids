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
	void BulletManager::Update(float, sf::Vector2f target);
	void BulletManager::AddBullet(sf::Vector2f, float);
	void BulletManager::AddPredatorBullet(sf::Vector2f, float, sf::Vector2f);
	list<Bullet*>& BulletManager::GetListOfBullets();
	list<Bullet*>& BulletManager::GetListOfPredBullets();
	bool BulletManager::IsColliding(sf::Vector2f targetPosition, int targetRadius);

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
	list<Bullet*> predBullets;

};

#endif 