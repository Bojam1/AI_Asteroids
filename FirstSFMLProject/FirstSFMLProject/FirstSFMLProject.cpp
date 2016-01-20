//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "Minimap.h"
#include "StateController.h"
#include "Menu.h"
#include "Play.h"

////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
	Menu* menu;
	Play* play;

	Player p1;
	Enemy enemies[3];
	

	enemies[1] = Enemy(sf::Vector2f(100, 100), 100);
	enemies[2] = Enemy(sf::Vector2f(10, 10), 50);

	for (int i = 0; i < 3; i++)
	{
		enemies[i].Load();
	}

	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML First Program");
	/*Initialsie the game modes*/

	menu = new Menu(SCREEN_WIDTH, SCREEN_HEIGHT);
	play = new Play(SCREEN_WIDTH, SCREEN_HEIGHT);

	Camera::GetInstance()->Init(800, 600);
	MiniMap::GetInstance()->Init(800, 600);
	//load a font
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");


	//create a circle
	sf::CircleShape circle(50);
	
	sf::CircleShape circle2(100);
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
			play->Update(t, time);
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
	


		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame
	
	return EXIT_SUCCESS;
}