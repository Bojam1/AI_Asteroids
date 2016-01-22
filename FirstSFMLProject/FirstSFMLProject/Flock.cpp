#include "stdafx.h"
#include "Flock.h"

using namespace std;

// =============================================== //
// ======== Flock Functions from Flock.h ========= //
// =============================================== //

int Flock::getSize()
{
	return flock.size();
}

Boid Flock::getBoid(int i)
{
	return flock[i];
}

Boid Flock::getPredBoid(int i)
{
	return predatorFlock[i];
}

void Flock::addBoid(Boid b)
{
	flock.push_back(b);
}

void Flock::addPredatorBoid(Boid pB)
{
	predatorFlock.push_back(pB);
}

// Runs the run function for every boid in the flock checking against the flock
// itself. Which in turn applies all the rules to the flock.
void Flock::flocking() 
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].run(flock);
	}
}
void Flock::PredFlocking()
{
	for (int i = 0; i < predatorFlock.size(); i++)
	{
		predatorFlock[i].run(predatorFlock);
	}
}
// Runs the swarm function for every boid in the flock checking against the flock
// itself. Which in turn applies all the rules to the flock.
void Flock::swarming(sf::Vector2f playerPos)
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].swarm(flock, playerPos);
	}
}