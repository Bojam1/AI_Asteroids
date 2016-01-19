//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
#include "Player.h"
//#include "Enemy.h"
#include "Camera.h"
#include "Minimap.h"

#include <iostream>
#include <vector>
#include "Boid.h"
#include "Pvector.h"
#include "Flock.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>
using namespace std;

////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	float boidsSize = 3;
	string action = "flock";

	Player p1;
	sf::Texture m_BGTexture;
	m_BGTexture.loadFromFile("bg.jpg");
	sf::Sprite m_BGSprite;
	sf::Sprite m_BGMapSprite;
	m_BGSprite.setTexture(m_BGTexture);
	m_BGSprite.setPosition(0, 0);

	m_BGMapSprite.setTexture(m_BGTexture);
	m_BGMapSprite.setColor(sf::Color(255, 255, 255, 100));
	//Enemy enemies[3];
	//
	//enemies[1] = Enemy(sf::Vector2f(100, 100), 100);
	//enemies[2] = Enemy(sf::Vector2f(10, 10), 50);

	//for (int i = 0; i < 3; i++)
	//{
	//	enemies[i].Load();
	//}

	// Create the main window
	const int window_width = 800;
	const int window_height = 600;
	sf::RenderWindow window(sf::VideoMode(window_width, window_height, 32), "SFML First Program");
	Camera::GetInstance()->Init(window_width, window_height);
	MiniMap::GetInstance()->Init(window_width, window_height);
	//load a font
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");

	//Create flock, vector of shapes, and initialize boids
	Flock flock;
	vector<sf::CircleShape> shapes;

	for (int i = 0; i < 25; i++) //Number of boids is hardcoded for testing pusposes.
	{
		//Boid b(rand() % window_width, rand() % window_height); //Starts the boid with a random position in the window.
		Boid b(window_width / 3, window_height / 3); //Starts all boids in the center of the screen
		sf::CircleShape shape(8, 3); //Shape with a radius of 10 and 3 points (Making it a triangle)

		//Changing the Visual Properties of the shape
		//shape.setPosition(b.location.x, b.location.y); //Sets position of shape to random location that boid was set to.
		shape.setPosition(window_width, window_height); //Testing purposes, starts all shapes in the center of screen.
		shape.setOutlineColor(sf::Color(0, 255, 0));
		shape.setFillColor(sf::Color::Green);
		shape.setOutlineColor(sf::Color::White);
		shape.setOutlineThickness(1);
		shape.setRadius(boidsSize);

		//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
		flock.addBoid(b);
		shapes.push_back(shape);
	}


	////create a circle
	//sf::CircleShape circle(50);
	//
	//sf::CircleShape circle2(100);

	sf::Time time;
	sf::Clock m_clock;

	// Start game loop 
	while (window.isOpen())
	{
		// Process events 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Close window : exit 
			if (Event.type == sf::Event::Closed)
				window.close();

			// Escape key : exit 
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();

			if ((Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Space))
			if (action == "flock")
				action = "swarm";
			else
				action = "flock";

		}

		time = m_clock.getElapsedTime();
		float t = time.asSeconds();
		m_clock.restart();

		p1.Update(t);


		window.clear(); //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>CLEAR WINDOW

		//prepare frame
		window.setView(Camera::GetInstance()->getView());
		//draw frame items
		window.draw(m_BGSprite);
		p1.Draw(window);


	
		//Draws all of the Boids out, and applies functions that are needed to update.
		for (int i = 0; i < shapes.size(); i++)
		{
			window.draw(shapes[i]);

			//Cout's removed due to slowdown and only needed for testing purposes
			//cout << "Boid "<< i <<" Coordinates: (" << shapes[i].getPosition().x << ", " << shapes[i].getPosition().y << ")" << endl;
			//cout << "Boid Code " << i << " Location: (" << flock.getBoid(i).location.x << ", " << flock.getBoid(i).location.y << ")" << endl;

			//Matches up the location of the shape to the boid
			shapes[i].setPosition(flock.getBoid(i).location.x, flock.getBoid(i).location.y);

			// Calculates the angle where the velocity is pointing so that the triangle turns towards it.
			float theta;
			theta = flock.getBoid(i).angle(flock.getBoid(i).velocity);
			shapes[i].setRotation(theta);
		}

		//MiniMap>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		//window.setView(MiniMap::GetInstance()->getView());
		//window.draw(m_BGSprite);
		//for (int i = 0; i < shapes.size(); i++)
		//{
		//	window.draw(shapes[i]);
		//}
		//p1.Draw(window);

		window.setView(MiniMap::GetInstance()->getStaticView());
		//p1.Draw(window);
		window.draw(m_BGMapSprite);
		for (int i = 0; i < shapes.size(); i++)
		{
			window.draw(shapes[i]);
		}
		//p1.Draw(window);
		p1.DrawOnMap(window);

		//MiniMap>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		//Applies the three rules to each boid in the flock and changes them accordingly.
		if (action == "flock")
			flock.flocking();
		else
			flock.swarming();

		// Finally, display rendered frame on screen 
		window.display(); //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>DRAW WINDOW
	} //loop back for next frame
	
	return EXIT_SUCCESS;
}