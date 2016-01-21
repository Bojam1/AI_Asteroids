#include "stdafx.h"
#include "PowerUp.h"

PowerUp::PowerUp() {
	if (!m_texture.loadFromFile("Lightning.png"))
	{
		// error...
	}
	sprite.setTexture(m_texture);
	sprite.setOrigin(50, 50);

	m_position = sf::Vector2f((rand() % 800 + 1), rand() % 600 + 1);

	sprite.setPosition(m_position);


}
bool PowerUp::IsColliding(Player * p)
{
	if (isAlive) {
		if (sprite.getGlobalBounds().intersects(p->GetSprite().getGlobalBounds()))
		{
		//	cout << "collision" << endl;
			p->PowerUpCollected();
			isAlive = false;
			return true;
		}
	}
	return false;
}
bool PowerUp::IsAlive() {
	return isAlive;
}
void PowerUp::Update(float time) {
	sprite.setPosition(m_position);
}
void PowerUp::Draw(sf::RenderWindow& window) {
	if (isAlive) {
		window.draw(sprite);
	}
}
sf::Sprite PowerUp::GetSprite()
{
	return sprite;
}