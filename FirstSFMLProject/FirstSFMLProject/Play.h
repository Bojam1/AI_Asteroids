#ifndef PLAY_H
#define PLAY_H

#include <iostream>
#include "StateController.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "Asteroids.h"
#include "MiniMap.h"
#include "AsteroidManager.h"
#include "PowerUpManager.h"
#include "PowerUp.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "Flock.h"
#include "Boid.h"
#include "FactoryShip.h"

class Play{
private:
	Player* player;
	Asteroids* asteroid;
	FactoryShip* factoryShip;
	Enemy enemies[3];
	sf::Sprite m_BGSprite;
	sf::Sprite m_BGMapSprite;
	sf::Texture m_BGTexture;
	

public:
	Play(int w, int h);
	~Play(){
		delete player;
	}
	void Init();
	void Update(float time, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	

};
#endif