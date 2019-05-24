// Game.cpp
// Implementation of the Game class.
// Date Created:	May 22, 2019
// Last Modified:	May 22, 2019
// Created by:		Tommy Janna

#include "Game.h"

Game::Game()
{
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Maze Game");
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
}

void Game::Draw()
{
	window.clear();
	
			//for(int i = 0; i < SIZE; i++) // Draw each node in list.
		//{
		//	window.draw(list.GetNodeAt(i)->rectangle);
		//}
	
	window.display();
}

void Game::Cleanup()
{
	//delete(window);
	
	//window = nullptr;
	return;
}
