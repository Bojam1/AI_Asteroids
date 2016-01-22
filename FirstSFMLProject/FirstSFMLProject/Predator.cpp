#include "stdafx.h"
#include "Predator.h"


Predator::Predator(Pvector predBoidPos, sf::Texture* predatorImage, float rotation)
{
	m_sprite.setTexture(*predatorImage);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_position.x = predBoidPos.x;
	m_position.y = predBoidPos.y;
}


Predator::~Predator()
{

}

void Predator::Draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}

bool Predator::WrapCheck()
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

void Predator::Update(float time, Pvector predBoidPos, float rotation)
{
	//cout << "rotationBullet: " << m_rotation << endl;
	//m_position += sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation))) * time * m_speed;
	//m_position += Player::GetInstance()->GetDirection() * time * Player::GetInstance()->GetSpeed();
	//cout << "bullet pos: " << "(" << m_position.x << "," << m_position.y << ")" << endl;
	sf::Vector2f pos;
	pos.x = predBoidPos.x;
	pos.y = predBoidPos.y;
	m_sprite.setPosition(pos);
	m_sprite.setRotation(rotation);

	//WrapCheck();
}