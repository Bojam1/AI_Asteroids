#ifndef PLAYER 
#define PLAYER

class Player
{
public:
	//Functions
	Player();
	Player(sf::Vector2f pos, sf::Vector2f dir, sf::FloatRect bounds);
	~Player()
	{
		delete instance;
		instanceFlag = false;
	}
	static Player* GetInstance();

	void Update(float time);
	void Draw(sf::RenderWindow& window);
	void DrawOnMap(sf::RenderWindow& window);
	sf::Vector2f GetPosition();
	float GetRotation();
	sf::Vector2f GetDirection();
	float GetSpeed();
	void Shoot();
	//Variables

protected:
	//Functions
	void Move(float time);
	void Rotation(int dir, float);
	void WrapAroundScreen();
	
	//
	static bool instanceFlag;
	static Player* instance;
	//Variables
	int m_width;
	int m_height;
	float m_speed;
	float m_rotation;
	float m_prevRot;
	float m_rotationDif;
	float toRadians(float degrees);
	sf::Vector2f m_position;
	sf::Vector2f m_direction;
	sf::Vector2f m_prevDir;
	sf::Vector2f bulletDir;
	sf::Sprite m_sprite;
	sf::Texture m_textureStandby;
	sf::Texture m_textureForward;
	sf::Texture m_textureLeft;
	sf::Texture m_textureRight;
	sf::FloatRect m_bounds;

private:

};

#endif