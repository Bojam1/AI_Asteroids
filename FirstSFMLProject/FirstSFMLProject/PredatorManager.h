#include <iostream>

#include <list>
using namespace std;

#ifndef PREDATORMANAGER
#define PREDATORMANAGER

#include "Predator.h"
#include "Pvector.h"

class PredatorManager
{
public:
	~PredatorManager()
	{
		delete instance;
		instanceFlag = false;
	}

	static PredatorManager* GetInstance();

	void Draw(sf::RenderWindow& window);
	void AddPredator(Pvector PredPos, float rotation);
	//list<Predator*>& PredatorManager::GetListOfPredators();
	bool IsColliding(sf::Vector2f targetPosition, int targetRadius);
	void Update(float, Pvector, float);

private:
	PredatorManager()
	{
		predators = list<Predator*>();
		predatorTexture.loadFromFile("Predator.png");
	}
	static bool instanceFlag;
	static PredatorManager* instance;
	sf::Texture predatorTexture;
	list<Predator*> predators;
};

#endif 
