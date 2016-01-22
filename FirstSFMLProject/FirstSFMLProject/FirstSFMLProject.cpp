//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
#include "Player.h"
//#include "Enemy.h"
#include "Camera.h"
#include "Minimap.h"
#include "Bullet.h"
#include <iostream>
#include <vector>
#include "Boid.h"
#include "Pvector.h"
#include "Flock.h"
#include "BulletManager.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>
#include "StateController.h"
#include "Menu.h"
#include "Play.h"

using namespace std;

////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	float boidsSize = 8;
	string action = "flock";


	// Create the main window
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	const int window_height = desktop.height;
	const int window_width = desktop.width;

	
	sf::RenderWindow window(sf::VideoMode(window_width, window_height, 32), "AI Project", sf::Style::None);
	Camera::GetInstance()->Init(window_width, window_height);
	MiniMap::GetInstance()->Init(window_width, window_height);
	//load a font
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");
	//int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
	Menu* menu;
	Play* play;

	//Create flock, vector of shapes, and initialize boids
	//Flock flock;
	//vector<sf::CircleShape> shapes;

	//for (int i = 0; i < 25; i++) //Number of boids is hardcoded for testing pusposes.
	//{
	//	//Boid b(rand() % window_width, rand() % window_height); //Starts the boid with a random position in the window.
	//	Boid b((window_width * 3) / 2, (window_height * 3) / 2 -150); //Starts all boids in the center of the screen
	//	sf::CircleShape shape(boidsSize, 3); //Shape with a radius of 10 and 3 points (Making it a triangle)

	//	//Changing the Visual Properties of the shape
	//	//shape.setPosition(b.location.x, b.location.y); //Sets position of shape to random location that boid was set to.
	//	shape.setPosition(window_width, window_height); //Testing purposes, starts all shapes in the center of screen.
	//	shape.setOutlineColor(sf::Color(0, 255, 0));
	//	shape.setFillColor(sf::Color::Green);
	//	shape.setOutlineColor(sf::Color::White);
	//	shape.setOutlineThickness(1);
	//	shape.setRadius(boidsSize);

	//	//Adding the boid to the flock and adding the shapes to the vector<sf::CircleShape>
	//	flock.addBoid(b);
	//	shapes.push_back(shape);
	//	
	//}

	menu = new Menu(window_width, window_height);
	play = new Play(window_width, window_height);


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
		}

		time = m_clock.getElapsedTime();
		float t = time.asSeconds();
		m_clock.restart();


		//updates
		switch (StateController::GetInstance()->getState())
		{
		case StateController::MENU:
			menu->Update(t);
			break;
		case StateController::PLAY:
			play->Update(t, window);
			break;
		case StateController::CREDITS:
			break;
		case StateController::PAUSE:
			break;
		case StateController::SPLASH:
			break;
		case StateController::SCORESCREEN:
			break;
		}//end switch


		window.clear();
		
		//draw
		switch (StateController::GetInstance()->getState())
		{
		case StateController::MENU:
			menu->Draw(window);
			break;
		case StateController::PLAY:
			play->Draw(window);
			break;
		case StateController::CREDITS:
			break;
		case StateController::PAUSE:
			break;
		case StateController::SPLASH:
			break;
		case StateController::SCORESCREEN:
			break;
		}//end switch

		
		window.display(); //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>DRAW WINDOW
	} //loop back for next frame
	
	return EXIT_SUCCESS;
}