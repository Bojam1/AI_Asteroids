#include "stdafx.h"
#include "Enemy.h"


//PUBLIC
Enemy::Enemy()
{
	m_sprite.setOrigin(40, 35);

	m_speed = 200;
	m_rotation = 0;
	m_sprite.setRotation(m_rotation);
	m_direction = sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation)));
	m_position = sf::Vector2f(300, 200);
}

Enemy::Enemy(sf::Vector2f pos, float speed)
{
	
	m_sprite.setOrigin(40, 35);
	m_speed = speed;
	m_rotation = 0;
	m_sprite.setRotation(m_rotation);
	m_direction = sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation)));
	
	m_position = sf::Vector2f(pos.x, pos.y);
}
void Enemy::Load()
{
	if (!m_texture.loadFromFile("enemy.png"))
		{
			// error...
		}
	m_sprite.setTexture(m_texture);
}

void Enemy::Update(float time, sf::Vector2f playerPos)
{
	GetDirection(playerPos);
	Move(time, playerPos);
	WrapAroundScreen();
}

void Enemy::Draw(sf::RenderWindow& window)
{
	m_sprite.setRotation(m_rotation);
	window.draw(m_sprite);
}


//PRIVATE

void Enemy::Move(float time, sf::Vector2f playerPos)
{
	float len = DistanceFrom(m_position, playerPos);
	if (len > 100)
	{
		m_position += m_direction * time * m_speed;
		m_sprite.setPosition(m_position);
	}
	
}

void Enemy::WrapAroundScreen()
{
	//if (m_position.x > 800)
	//	m_position.x = 0;
	//else if (m_position.x < 0)
	//	m_position.x = 800;

	//if (m_position.y > 600)
	//	m_position.y = 0;
	//else if (m_position.y < 0)
	//	m_position.y = 600;

}

void Enemy::Rotation(int dir)
{
	m_rotation += 0.1 * dir;
	m_direction = sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation)));
}

float Enemy::toRadians(float degrees)
{
	return (degrees * 3.14) / 180;
}

void Enemy::GetDirection(sf::Vector2f playerPos)
{
	sf::Vector2f dir = playerPos - m_position;
	dir = Normalise(dir);
	//m_direction = dir;

	m_direction = SlowTurn(m_direction, dir);

	m_rotation = atan2f(m_direction.y, m_direction.x) * 180 / 3.14;
	//m_rotation = atan2f(dir.y, dir.x) * 180 / 3.14;
	m_sprite.setRotation(m_rotation);
}

sf::Vector2f Enemy::Normalise(sf::Vector2f vec)
{
	float len = sqrt(vec.x * vec.x + vec.y * vec.y);
	return sf::Vector2f(vec.x/len, vec.y/len);
}

float Enemy::DistanceFrom(sf::Vector2f enemy, sf::Vector2f player)
{
	float len = sqrt((player.x - enemy.x)*(player.x - enemy.x) + (player.y - enemy.y)*(player.y - enemy.y));
	return len;
}

sf::Vector2f Enemy::SlowTurn(sf::Vector2f m_direction, sf::Vector2f dir)
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
