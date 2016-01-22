#include "stdafx.h"
#include "FactoryShip.h"

#include "SFML\Graphics.hpp"
#include "Pvector.h"
#include "BulletManager.h"
#include <list>

//PUBLIC
FactoryShip::FactoryShip()
{
	m_sprite.setOrigin(40, 35);

	m_speed = 200;
	m_rotation = 0;
	m_sprite.setRotation(m_rotation);
	m_direction = sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation)));
	m_position = sf::Vector2f(300, 200);
	
}

FactoryShip::FactoryShip(sf::Vector2f pos, float speed)
{

	m_sprite.setOrigin(40, 35);
	m_speed = speed;
	m_rotation = 0;
	m_sprite.setRotation(m_rotation);
	m_direction = sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation)));

	m_position = sf::Vector2f(pos.x, pos.y);
}
void FactoryShip::Load()
{
	if (!m_texture.loadFromFile("enemy.png"))
	{
		cout << "ERROR LOADING ENEMY" << endl;
	}
	m_sprite.setTexture(m_texture);
}

void FactoryShip::Update(float time, sf::Vector2f playerPos)
{
	GetDirection(playerPos);
	Move(time, playerPos);
	WrapAroundScreen();

	if (timer.getElapsedTime().asSeconds() > 5)
	{
		BulletManager::GetInstance()->AddPredatorBullet(m_position, m_rotation, playerPos);
		timer.restart();
	}
}

void FactoryShip::Draw(sf::RenderWindow& window)
{
	m_sprite.setRotation(m_rotation);
	window.draw(m_sprite);
}


//PRIVATE

void FactoryShip::Move(float time, sf::Vector2f target)
{
	float len = DistanceFrom(m_position, target);
	if (len > 100)
	{
		m_position += m_direction * time * m_speed;
		m_sprite.setPosition(m_position);
	}
	
	
}

void FactoryShip::WrapAroundScreen()
{
	if (m_position.x > (800 * 3) - 20)
		m_position.x = 20;
	else if (m_position.x < 20)
		m_position.x = (800 * 3) - 20;

	if (m_position.y >(600 * 3) - 20)
		m_position.y = 20;
	else if (m_position.y < 20)
		m_position.y = (600 * 3) - 20;

}

void FactoryShip::Rotation(int dir)
{
	m_rotation += 0.1 * dir;
	m_direction = sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation)));
}

float FactoryShip::toRadians(float degrees)
{
	return (degrees * 3.14) / 180;
}

void FactoryShip::GetDirection(sf::Vector2f playerPos)
{
	sf::Vector2f dir = playerPos - m_position;
	dir = Normalise(dir);
	//m_direction = dir;

	m_direction = SlowTurn(m_direction, dir);

	m_rotation = atan2f(m_direction.y, m_direction.x) * 180 / 3.14;
	//m_rotation = atan2f(dir.y, dir.x) * 180 / 3.14;
	m_sprite.setRotation(m_rotation);
}

sf::Vector2f FactoryShip::Normalise(sf::Vector2f vec)
{
	float len = sqrt(vec.x * vec.x + vec.y * vec.y);
	return sf::Vector2f(vec.x / len, vec.y / len);
}

float FactoryShip::DistanceFrom(sf::Vector2f enemy, sf::Vector2f player)
{
	float len = sqrt((player.x - enemy.x)*(player.x - enemy.x) + (player.y - enemy.y)*(player.y - enemy.y));
	return len;
}

sf::Vector2f FactoryShip::SlowTurn(sf::Vector2f m_direction, sf::Vector2f dir)
{
	if (m_direction.x < dir.x)
		m_direction.x += 0.0001;
	else if (m_direction.x > dir.x)
		m_direction.x -= 0.0001;

	if (m_direction.y < dir.y)
		m_direction.y += 0.0001;
	else if (m_direction.y > dir.y)
		m_direction.y -= 0.0001;

	return m_direction;
}
