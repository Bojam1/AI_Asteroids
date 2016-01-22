#include "stdafx.h"
#include "Play.h"

string action = "flock";
sf::CircleShape circle(50);

sf::CircleShape circle2(100);
Flock flock;
vector<sf::CircleShape> shapes;

Play::Play(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	//sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	//const int window_height = desktop.height;
	//const int window_width = desktop.width;
	//cout << SCREEN_WIDTH << endl;
	float boidsSize = 8;
	


	player = new Player();
	
	//Enemy enemies[3];S
	asteroid = new Asteroids(player->GetPosition());

	//enemies[1] = Enemy(sf::Vector2f(100, 100), 100);
	//enemies[2] = Enemy(sf::Vector2f(10, 10), 50);

	//for (int i = 0; i < 3; i++)
	//{
	//	enemies[i].Load();
	//}

	m_BGTexture.loadFromFile("bg.jpg");
	m_BGSprite.setTexture(m_BGTexture);
	m_BGSprite.setPosition(0, 0);

	m_BGMapSprite.setTexture(m_BGTexture);
	m_BGMapSprite.setColor(sf::Color(255, 255, 255, 100));

	//Flock flock;
	//vector<sf::CircleShape> shapes;

	for (int i = 0; i < 25; i++) //Number of boids is hardcoded for testing pusposes.
	{
		//Boid b(rand() % window_width, rand() % window_height); //Starts the boid with a random position in the window.
		Boid b((SCREEN_WIDTH * 3) / 2, (SCREEN_HEIGHT * 3) / 2 - 150); //Starts all boids in the center of the screen
		sf::CircleShape shape(boidsSize, 3); //Shape with a radius of 10 and 3 points (Making it a triangle)

		//Changing the Visual Properties of the shape
		//shape.setPosition(b.location.x, b.location.y); //Sets position of shape to random location that boid was set to.
		shape.setPosition(SCREEN_WIDTH, SCREEN_HEIGHT); //Testing purposes, starts all shapes in the center of screen.
		shape.setOutlineColor(sf::Color(0, 255, 0));
		shape.setFillColor(sf::Color::Green);
		shape.setOutlineColor(sf::Color::White);
		shape.setOutlineThickness(1);
		shape.setRadius(boidsSize);

		//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
		flock.addBoid(b);
		shapes.push_back(shape);

	}

	Camera::GetInstance()->Init(SCREEN_WIDTH, SCREEN_HEIGHT);
	MiniMap::GetInstance()->Init(SCREEN_WIDTH, SCREEN_HEIGHT);
	AsteroidManager::GetInstance()->Init(player->GetPosition());
	PowerUpManager::GetInstance()->Init();
}

void Play::Init()
{

}

void Play::Update(float time,  sf::RenderWindow& window){

	player->Update(time);

	//for (int i = 0; i < 3; i++)
	//{
	//	enemies[i].Update(time, player->GetPosition());
	//}
	asteroid->Update(time);
	AsteroidManager::GetInstance()->Update(time, player);
	PowerUpManager::GetInstance()->Update(time, player);
	BulletManager::GetInstance()->Update(time);

	if (action == "flock")
		flock.flocking();
	else
		flock.swarming(player->GetPosition());

	sf::Event Event;
	while (window.pollEvent(Event)){
		if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
			window.close();
		if ((Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Space))
		{
			player->Shoot();
		}
		if ((Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::S))
		if (action == "flock")
			action = "swarm";
		else
			action = "flock";
	}
}

void Play::Draw(sf::RenderWindow& window){

	//game Window
	window.setView(Camera::GetInstance()->getView());

	window.draw(m_BGSprite);

	
	//for (int i = 0; i < 3; i++)
	//{
	//	enemies[i].Draw(window);
	//}
	//asteroid->Draw(window);
	AsteroidManager::GetInstance()->Draw(window);
	PowerUpManager::GetInstance()->Draw(window);
	BulletManager::GetInstance()->Draw(window);
	//Draws all of the Boids out, and applies functions that are needed to update.
	for (int i = 0; i < shapes.size(); i++)
	{
		//Cout's removed due to slowdown and only needed for testing purposes
		//cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
		//cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;

		//Matches up the location of the shape to the boid
		shapes[i].setPosition(flock.getBoid(i).location.x, flock.getBoid(i).location.y);

		// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
		float theta;
		theta = flock.getBoid(i).angle(flock.getBoid(i).velocity);
		shapes[i].setRotation(theta);

		if (BulletManager::GetInstance()->IsColliding(shapes[i].getPosition(), shapes[i].getRadius()))
		{
			shapes[i].setOutlineColor(sf::Color::Red);
		}
		window.draw(shapes[i]);

		player->Draw(window);
	}

		//MiniMap
		window.setView(MiniMap::GetInstance()->getStaticView());
		window.draw(m_BGMapSprite);
		for (int i = 0; i < shapes.size(); i++)
		{
			window.draw(shapes[i]);
		}
		BulletManager::GetInstance()->Draw(window);
		AsteroidManager::GetInstance()->Draw(window);
		player->DrawOnMap(window);

		//reset view
		//window.setView(Camera::GetInstance()->getView());
}
