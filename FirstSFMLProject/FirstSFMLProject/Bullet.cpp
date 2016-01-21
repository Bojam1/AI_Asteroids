#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>

#include <iostream>
#include "Bullet.h"
#include "Player.h"


Bullet::Bullet()
{
}

Bullet::Bullet(sf::Vector2f playerPos, sf::Texture* bulletImage, float rotation)
{

	m_rotation = rotation;
	m_speed = 700;
	bulletSprite.setTexture(*bulletImage, true);
	bulletSprite.setPosition(playerPos);
	m_position = playerPos;
	bulletSprite.setOrigin(bulletSprite.getGlobalBounds().width / 2, bulletSprite.getGlobalBounds().height / 2);
	bulletSprite.setScale(0.3, 0.3);
}

//! Draw the bullet holes
/*!
\Draws the bullet holes on to the window
\return none
\sa
*/
void Bullet::Draw(sf::RenderWindow& window)
{
	//if (targetCollided != 0)
 	window.draw(bulletSprite);
}

sf::Vector2f Bullet::GetBulletPosition()
{
	return bulletSprite.getPosition();
}

void Bullet::Move(float time)
{
	//cout << "rotationBullet: " << m_rotation << endl;
	m_position += sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation))) * time * m_speed;
	//m_position += Player::GetInstance()->GetDirection() * time * Player::GetInstance()->GetSpeed();
	//cout << "bullet pos: " << "(" << m_position.x << "," << m_position.y << ")" << endl;
	bulletSprite.setPosition(m_position);
}

float Bullet::toRadians(float degrees)
{
	return (degrees * 3.14) / 180;
}

bool Bullet::CheckBullets()
{
	
	if (m_position.x > (800 * 3) - 20)
		return true;
	else if (m_position.x < 20)
		return true;

	if (m_position.y >(600 * 3) - 20)
		return true;
	else if (m_position.y < 20)
		return true;

	return false;

}