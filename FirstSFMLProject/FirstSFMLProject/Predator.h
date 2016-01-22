#pragma once

#include "Pvector.h"

class Predator
{
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	float m_rotation;
	sf::Vector2f m_position;

public:
	Predator(Pvector playerPos, sf::Texture* predatorImage, float rotation);
	~Predator();

	void Draw(sf::RenderWindow &window);
	bool WrapCheck();
	void Update(float time, Pvector, float);
};

