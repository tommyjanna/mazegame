// Game.cpp
// Implementation of the Game class.
// Date Created:	May 22, 2019
// Last Modified:	May 22, 2019
// Created by:		Tommy Janna

#include "Game.h"

// Declare static members.
LinkedList GameObject::objects;

Game::Game()
{
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Game");
	
	SceneManager::ChangeScene(SceneManager::MENU);
}

Game::~Game()
{
	Cleanup();
}

void Game::Run()
{
	while(window.isOpen())
	{
		Input();
		Update();
		Draw();
		
		// Halt the program for a rate of approx. 30 updates/sec.
		sleep(milliseconds(1000/30));
	}
	return;
}

void Game::Input()
{
	// Holds top event in queue.
	Event event;
	
	while(window.pollEvent(event)) // Obtain next input in queue and store it in event.
	{
		if(event.type == Event::Closed) // X button is pressed.
		{
			window.close();
		}
	}

}

void Game::Update()
{	
	// Update existing GameObjects
	for(int i = 0; i < GameObject::objects.GetSize(); i++)
	{
		GameObject::objects.GetLinkAt(i)->GetContent()->Update();
	}

	return;
}

void Game::Draw()
{
	window.clear();

	for(int i = 1; i < 5; i++)
	{
		for(int j = 0; j < GameObject::objects.GetSize(); j++)
		{
			if(GameObject::objects.GetLinkAt(j)->GetContent()->GetLayer() == i)
			{	
				// Draw to the back buffer.
				window.draw(*GameObject::objects.GetLinkAt(j)->GetContent()->GetDrawable());
			}
		}
	}

	window.display();
}

void Game::Cleanup()
{
	//delete(window);
	
	//window = nullptr;
	return;
}
