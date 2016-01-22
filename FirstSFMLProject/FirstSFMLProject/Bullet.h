#include <iostream>
#include <list>
using namespace std;

#ifndef BULLET
#define BULLET

class Bullet
{
public:
	Bullet();
	~Bullet()
	{
		cout << "Bullets deleted" << endl;
	}
	Bullet(sf::Vector2f, sf::Texture* bulletImage, float);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f Bullet::GetBulletPosition();
	void Move(float time);
	void Seek(float time, sf::Vector2f target);
	float DistanceFrom(sf::Vector2f pos, sf::Vector2f player);
	float toRadians(float degrees);
	bool CheckBullets();
	bool IsColliding(sf::Vector2f targetPosition, int targetRadius);

private:
	sf::Sprite bulletSprite;
	sf::Vector2f m_direction;
	sf::Vector2f m_position;
	float m_speed;
	float m_rotation;
	float m_radius;
};
#endif 