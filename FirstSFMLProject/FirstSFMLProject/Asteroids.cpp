#include "stdafx.h"
#include "Asteroids.h"

Asteroids::Asteroids(sf::Vector2f playerPos){
	if (!m_texture.loadFromFile("asteroid.png"))
	{
		// error...
	}
	sprite.setTexture(m_texture);
	sprite.setOrigin(40, 35);

	sf::Vector2f dir = playerPos - m_position;
	dir = Normalise(dir);
	m_dir = dir;

	m_position = sf::Vector2f((rand() % 800 + 1), rand() % 600 + 1);
	
	sprite.setPosition(m_position);
	

}
bool Asteroids::IsColliding(Player * p)
{
	if (sprite.getGlobalBounds().intersects(p->GetSprite().getGlobalBounds()))
	{
	//	cout << "collision" << endl;
	}
	return false;
}
bool Asteroids::IsAlive(){
	return isAlive; 
}
void Asteroids::Update(float time){

	m_position += m_dir * time * m_speed;
	sprite.setPosition(m_position);
	WrapAroundScreen();
}
void Asteroids::Draw(sf::RenderWindow& window){
	if (isAlive){
		window.draw(sprite);
	}
}
sf::Vector2f Asteroids::Normalise(sf::Vector2f vec)
{
	float len = sqrt(vec.x * vec.x + vec.y * vec.y);
	return sf::Vector2f(vec.x / len, vec.y / len);
}
void Asteroids::WrapAroundScreen()
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