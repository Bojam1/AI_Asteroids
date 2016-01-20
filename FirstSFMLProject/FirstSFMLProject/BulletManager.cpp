#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>

#include <iostream>

#include "BulletManager.h"

bool BulletManager::instanceFlag = false;
BulletManager* BulletManager::instance = NULL;

//! (Brief desc)
/*!
\(Detailed desc)
\return
\sa
*/
BulletManager* BulletManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new BulletManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

//! Adds bullets to a list
/*!
\When called, it is passed a bulletType and position when called in the Shoot() method in the bullet class
\the bulletType and position are passed from the Player class which holds the Shoot() method and determines these variables.
\return none
\sa
*/
void BulletManager::AddBullet(sf::Vector2f bulletPos, float rotation)
{
	Bullet* b = new Bullet(bulletPos, &bulletTexture, rotation);
	bullets.push_back(b);
	cout << "rotationBullet: " << bullets.size() << endl;
}

//! Draws the bullet holes
/*!
\When called, the Draw() method iterates through the list of bullets.
\It then calls upon the Draw() method inside the BulletHole class to draw the bullets to the screen.
\return none
\sa
*/
void BulletManager::Draw(sf::RenderWindow& window)
{
	for (Bullet* b: bullets)
	{
		b->Draw(window);
	}
}

void BulletManager::Update(float t)
{
	for (Bullet* b : bullets)
	{
		b->Move(t);

		if (b->CheckBullets() == true)
		{
			bullets.erase(std::remove(bullets.begin(), bullets.end(), b), bullets.end()); //iterate from the start to the end of the list, find b and erase it
			break;
		}
		
	}
}

list<Bullet*>& BulletManager::GetListOfBullets()
{
	return bullets;
}