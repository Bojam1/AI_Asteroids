#include "stdafx.h"
#include "Play.h"

Enemy enemies[3];

Play::Play(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{

	cout << SCREEN_WIDTH << endl;

	player = new Player();
	
	//Enemy enemies[3];S
	asteroid = new Asteroids(player->GetPosition());

	enemies[1] = Enemy(sf::Vector2f(100, 100), 100);
	enemies[2] = Enemy(sf::Vector2f(10, 10), 50);

	for (int i = 0; i < 3; i++)
	{
		enemies[i].Load();
	}

	Camera::GetInstance()->Init(SCREEN_WIDTH, SCREEN_HEIGHT);
	MiniMap::GetInstance()->Init(SCREEN_WIDTH, SCREEN_HEIGHT);

}

void Play::Init()
{

}

void Play::Update(float time, sf::Time animationTime){

	player->Update(time);

	for (int i = 0; i < 3; i++)
	{
		enemies[i].Update(time, player->GetPosition());
	}
	asteroid->Update(time);
}

void Play::Draw(sf::RenderWindow& window){

	//game Window
	window.draw(background);
	player->Draw(window);
	for (int i = 0; i < 3; i++)
	{
		enemies[i].Draw(window);
	}	
	asteroid->Draw(window);
	//MiniMap
	window.setView(MiniMap::GetInstance()->getView());
	window.draw(background);
	for (int i = 0; i < 3; i++)
	{
		enemies[i].Draw(window);
	}	
	player->Draw(window);
	window.setView(MiniMap::GetInstance()->getStaticView());
	//reset view
	window.setView(Camera::GetInstance()->getView());
}

void Play::ResetAll(){

}