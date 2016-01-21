#include "stdafx.h"


#include "AsteroidManager.h"


bool AsteroidManager::instanceFlag = false;
AsteroidManager* AsteroidManager::instance = NULL;

AsteroidManager* AsteroidManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new AsteroidManager();
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}
void AsteroidManager::Init(sf::Vector2f playerPos)
{
	for (int i = 0; i < max_Asteroids; i++)
	{
		asteroids->push_back(new Asteroids(playerPos));
	}

}
void AsteroidManager::Update(float time, Player* p)
{
	//cout << p->GetPosition().x << ":" << p->GetPosition().y << endl;
	for each(Asteroids* asteroid in *asteroids)
	{
		asteroid->Update(time);
	}
	for each(Asteroids* asteroid in *asteroids)
	{
		asteroid->IsColliding(p);
	}
}
void AsteroidManager::AddAsteroid(sf::Vector2f playerPos)
{
	asteroids->push_back(new Asteroids( playerPos));
}

void AsteroidManager::Draw(sf::RenderWindow& window)
{
	for each(Asteroids* asteroid in *asteroids)
	{
		asteroid->Draw(window);
	}

}