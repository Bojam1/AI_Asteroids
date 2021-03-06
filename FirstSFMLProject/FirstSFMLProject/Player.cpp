#include "stdafx.h"
#include "Player.h"
#include "Camera.h"
#include "Minimap.h"
#include "BulletManager.h"
#include <iostream>
#include <math.h>

bool Player::instanceFlag = false;
Player* Player::instance = NULL;

//! (Brief desc)
/*!
\(Detailed desc)
\return
\sa
*/
Player* Player::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new Player;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

//PUBLIC
Player::Player()
{
	//if (!m_texture.loadFromFile("player.png"))
	//{
	//	// error...
	//}
	if (!m_textureStandby.loadFromFile("player.png")){}
	if (!m_textureForward.loadFromFile("player1.png")){}
	if (!m_textureLeft.loadFromFile("player3.png")){}
	if (!m_textureRight.loadFromFile("player2.png")){}
	m_sprite.setTexture(m_textureStandby);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_position = sf::Vector2f(0, 0);

	m_speed = 0;
	count = 0;
	m_rotation = 0;
	m_prevRot = 0;
	m_rotationDif = 0;
	m_direction = sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation)));
	m_prevDir = sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation)));
	m_position = sf::Vector2f((800 * 3) / 2, (600 * 3) / 2);
}

Player::Player(sf::Vector2f pos, sf::Vector2f dir, sf::FloatRect bounds)
{

}

void Player::Update(float time)
{
	Move(time);
	WrapAroundScreen();

	
}

void Player::Draw(sf::RenderWindow& window)
{
	m_sprite.setRotation(m_rotation);
	window.draw(m_sprite);
}

void Player::DrawOnMap(sf::RenderWindow& window)
{
	sf::CircleShape circle;
	circle.setRadius(40);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(10);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(m_sprite.getPosition());
	//window.draw(m_sprite);
	window.draw(circle);
}


void Player::Move(float time)
{
	//m_position += m_direction * time * m_speed;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_sprite.setTexture(m_textureStandby);
	}
	if (powerUpCollected)
	{
		//count = 0;
		m_speed = 650;
		count++;
		cout << count << endl;
			if(count == 360)
			{
				m_speed = 500;
				count = 0;
				powerUpCollected = false;
				cout << "power lost" << endl;
			}
	}
	//m_position += m_direction * time * m_speed;
	//m_sprite.setPosition(m_position);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_sprite.setTexture(m_textureLeft);
		Rotation(1, time);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_sprite.setTexture(m_textureRight);
		Rotation(-1, time);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_sprite.setTexture(m_textureForward);

		/*m_rotationDif = m_prevRot - m_rotation;
		if (m_rotationDif < 0)
			m_rotationDif *= -1;
		if (m_rotationDif > 180)
			m_rotationDif = 360 - m_rotationDif;*/
		//cout << "rotationDif: " << m_rotationDif << endl;

		//m_position += m_direction * time * m_speed;

		m_prevDir = m_direction;
		m_prevRot = m_rotation;

		if (m_speed <= 500)
		{
			m_speed += 2;
		}
	}
	else if (m_speed > 35)
	{
		m_speed -= 1;
	}

	cout << m_speed << endl;


	m_position += m_prevDir * time * m_speed;
	m_sprite.setPosition(m_position);

	//cout << "speed: " << m_speed << endl;
	Camera::GetInstance()->setViewPosition(sf::Vector2f(m_position.x, m_position.y));
	MiniMap::GetInstance()->setViewPosition(sf::Vector2f(m_position.x, m_position.y));
}

void Player::WrapAroundScreen()
{
	if (m_position.x > (800*3)-20)
		m_position.x = 20;
	else if (m_position.x < 20)
		m_position.x = (800 * 3)-20;

	if (m_position.y > (600*3)-20)
		m_position.y = 20;
	else if (m_position.y < 20)
		m_position.y = (600*3)-20;

}

void Player::Rotation(int dir, float time)
{
	m_rotation += 200 * dir * time;
	//cout << "rotation: " << m_rotation << endl;
	if (m_rotation >= 360 || m_rotation <= -360)
	{
		m_rotation = 0;
	}
	m_direction = sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation)));
}

float Player::toRadians(float degrees)
{
	return (degrees * 3.14) / 180;
}

sf::Vector2f Player::GetPosition()
{
	return m_position;
}

float Player::GetRotation()
{
	return m_rotation;
}

void Player::Shoot()
{
	BulletManager::GetInstance()->AddBullet(m_position, m_rotation);
}

sf::Vector2f Player::GetDirection()
{
	return m_direction;
}

float Player::GetSpeed()
{
	return m_speed;
}
sf::Sprite Player::GetSprite()
{
	return m_sprite;
}

void Player::PowerUpCollected()
{
	powerUpCollected = true;
	cout << "powerUpcollected" << endl;
}
