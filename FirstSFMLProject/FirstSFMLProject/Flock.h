#include <vector>
#include "Boid.h"


#ifndef FLOCK_H_
#define FLOCK_H_

/*
Brief description of Flock Class:
// This file contains the class needed to create flock of boids. It utilizes
// the boids class and initializes boid flocks with parameters that can be
// specified. This class will be utilized in main.
*/

class Flock
{
private:

public:
	//Public Variables
	vector<Boid> flock;
	vector<Boid> predatorFlock;

	//Constructors
	Flock() {}
/*
Commented out for now, since including destructors causes g++ to spit back
errors. 
	//Destructor
	Flock::~Flock()
	{
		//cout << "Flock is being deleted by destructor!" << endl;
	}
*/
	//Accessor functions
	int getSize();
	Boid getBoid(int i);
	Boid getPredBoid(int i);
	//Mutator Functions
	void addBoid(Boid b);
	void addPredatorBoid(Boid pB);
	void flocking();
	void PredFlocking();
	void swarming(sf::Vector2f);

};

#endif