#ifndef PLAY_H
#define PLAY_H

#include <iostream>
#include "StateController.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "Asteroids.h"
#include "MiniMap.h"


class Play{
private:
	Player* player;
	Asteroids* asteroid;
	sf::Texture backgroundTexture;
	sf::Sprite background;

public:
	Play(int w, int h);
	~Play(){
		delete player;
	}
	void Init();
	void Update(float time, sf::Time animationTime);
	void Draw(sf::RenderWindow& window);
	void ResetAll();

};
#endif