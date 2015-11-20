#ifndef PLAYER 
#define PLAYER

class Player
{
public:
	//Functions
	Player();
	Player(sf::Vector2f pos, sf::Vector2f dir, sf::FloatRect bounds);

	void Update(float time);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition();
	//Variables

protected:
	//Functions
	void Move(float time);
	void Rotation(int dir);
	void WrapAroundScreen();
	

	//Variables
	int m_width;
	int m_height;
	float m_speed;
	float m_rotation;
	float toRadians(float degrees);
	sf::Vector2f m_position;
	sf::Vector2f m_direction;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::FloatRect m_bounds;

private:

};

#endif