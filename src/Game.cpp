// Game.cpp
// Implementation of the Game class.
// Date Created:	May 22, 2019
// Last Modified:	May 22, 2019
// Created by:		Tommy Janna

#include "Game.h"

// Declare static members.
Vector2i Game::mousePos;
bool Game::mouseState[2];
LinkedList* GameObject::objects;

Game::Game()
{
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Game");
	GameObject::objects = new LinkedList();
	
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
	mouseEventOccur = false;
	
	while(window.pollEvent(event)) // Obtain next input in queue and store it in event.
	{
		if(event.type == Event::Closed) // X button is pressed.
		{
			window.close();
		}
		
		else if(event.type == Event::MouseButtonPressed)
		{
			mouseEventOccur = true;
			
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				mouseState[0] = true; // Pressed
				mouseState[1] = false; // Released
			}
		}
		
		else if(event.type == Event::MouseButtonReleased)
		{
			mouseEventOccur = true;

			if(event.mouseButton.button == sf::Mouse::Left)
			{
				mouseState[1] = true; // Released
				mouseState[0] = false; // Pressed
			}
		}
	}
	
	// If no mouse presses this tick, reset.
	if(!mouseEventOccur)
	{
		mouseState[0] = false;
		mouseState[1] = false;
	}
	
	// Refresh mouse position (relative to window)
	mousePos = Mouse::getPosition(window);

	return;
}

void Game::Update()
{	
	// Update existing GameObjects
	for(int i = 0; i < GameObject::objects->GetSize(); i++)
	{
		GameObject::objects->GetLinkAt(i)->GetContent()->Update();
	}

	return;
}

void Game::Draw()
{
	window.clear(Color(243, 240, 189));

	for(int i = 1; i < 6; i++)
	{
		for(int j = 0; j < GameObject::objects->GetSize(); j++)
		{
			if(GameObject::objects->GetLinkAt(j)->GetContent()->GetLayer() == i)
			{	
				// Draw to the back buffer.
				GameObject::objects->GetLinkAt(j)->GetContent()->UpdatePosition();
				window.draw(*GameObject::objects->GetLinkAt(j)->GetContent()->GetDrawable());
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
