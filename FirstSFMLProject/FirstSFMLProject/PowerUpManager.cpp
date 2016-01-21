#include "stdafx.h"


#include "PowerUpManager.h"


bool PowerUpManager::instanceFlag = false;
PowerUpManager* PowerUpManager::instance = NULL;

PowerUpManager* PowerUpManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new PowerUpManager();
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}
void PowerUpManager::Init()
{
	for (int i = 0; i < max_PowerUps; i++)
	{
		powerUps->push_back(new PowerUp());
	}

}
void PowerUpManager::Update(float time, Player* p)
{
	//cout << p->GetPosition().x << ":" << p->GetPosition().y << endl;
	for each(PowerUp* pUps in *powerUps)
	{
		pUps->Update(time);
	}
	for each(PowerUp* pUps in *powerUps)
	{
		pUps->IsColliding(p);
	}
}
void PowerUpManager::AddPowerUp()
{
	powerUps->push_back(new PowerUp());
}

void PowerUpManager::Draw(sf::RenderWindow& window)
{
	for each(PowerUp* pUps in *powerUps)
	{
		pUps->Draw(window);
	}

}