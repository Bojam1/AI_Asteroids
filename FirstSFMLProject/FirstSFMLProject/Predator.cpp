#include "stdafx.h"
#include "Predator.h"


Predator::Predator()
{
	if (!m_texture.loadFromFile("player.png")){}
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
}


Predator::~Predator()
{

}
