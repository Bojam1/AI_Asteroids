#include "stdafx.h"
#include "PredatorManager.h"

bool PredatorManager::instanceFlag = false;
PredatorManager* PredatorManager::instance = NULL;

//! (Brief desc)
/*!
\(Detailed desc)
\return
\sa
*/
PredatorManager* PredatorManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new PredatorManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void PredatorManager::AddPredator(Pvector PredPos, float rotation)
{
	Predator* b = new Predator(PredPos, &predatorTexture, rotation);
	predators.push_back(b);
}

void PredatorManager::Draw(sf::RenderWindow& window)
{
	for (Predator* p : predators)
	{
		p->Draw(window);
	}
}

void PredatorManager::Update(float t, Pvector predBoidPos, float theta)
{
	for (Predator* p : predators)
	{
		p->Update(t, predBoidPos, theta);

	}
}