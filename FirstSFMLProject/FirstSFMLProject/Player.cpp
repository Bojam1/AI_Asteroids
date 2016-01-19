#include "stdafx.h"
#include "Player.h"
#include "Camera.h"
#include "Minimap.h"

//PUBLIC
Player::Player()
{
	if (!m_texture.loadFromFile("player.png"))
	{
		// error...
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_position = sf::Vector2f(0, 0);

	m_speed = 500;
	m_rotation = 0;
	m_direction = sf::Vector2f(cos(toRadians(m_rotation)), sin(toRadians(m_rotation)));
	m_position = sf::Vector2f(300, 200);
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


//PRIVATE

void Player::Move(float time)
{

	m_position += m_direction * time * m_speed;
	m_sprite.setPosition(m_position);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		Rotation(1, time);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		Rotation(-1, time);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (m_speed <= 1000)
			m_speed += 0.1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (m_speed >= 0)
			m_speed -= 0.1;
	}
	Camera::GetInstance()->setViewPosition(sf::Vector2f(m_position.x, m_position.y));
	MiniMap::GetInstance()->setViewPosition(sf::Vector2f(m_position.x, m_position.y));
}

void Player::WrapAroundScreen()
{
	/*if (m_position.x > 800)
		m_position.x = 0;
	else if (m_position.x < 0)
		m_position.x = 800;

	if (m_position.y > 600)
		m_position.y = 0;
	else if (m_position.y < 0)
		m_position.y = 600;*/

}

void Player::Rotation(int dir, float time)
{
	m_rotation += 100 * dir * time;
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