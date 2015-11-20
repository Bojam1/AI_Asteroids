//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
#include "Player.h"
#include "Enemy.h"

////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
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
		time = m_clock.getElapsedTime();
		float t = time.asSeconds();
		m_clock.restart();

		p1.Update(t);

		for (int i = 0; i < 3; i++)
		{
			enemies[i].Update(t, p1.GetPosition());
		}

		//e1.Update(t, p1.GetPosition());

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

		//prepare frame
		window.clear();

		//draw frame items
		

		p1.Draw(window);

		for (int i = 0; i < 3; i++)
		{
			enemies[i].Draw(window);
		}

		//e1.Draw(window);

		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame
	
	return EXIT_SUCCESS;
}