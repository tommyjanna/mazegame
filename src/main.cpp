// main.cpp
// Project Title:		Maze Game
// Project Description:	A program that randomly generates a maze,
//						and gives the user the option to have the maze
//						solved by the computer, or play an adventure/RPG
//						like interactive mode.
// Date Created:		May 22, 2019
// Last Modified:		May 22, 2019
// Created by:			Tommy Janna

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(480, 480), "Visual Sort");
	Event event;	
	
	srand(time(nullptr));

	while(window.isOpen())
	{
		/// INPUT

		while(window.pollEvent(event)) // Obtain next input in queue.
		{
			if(event.type == Event::Closed) // X button is pressed.
			{
				window.close();
			}
		}
		
		/// SORTING
		
		//if(list.IsSorting()) // Not finished sorting.
		//{
			// Run next sort step.
		//	list.BubbleSortStep();
		//}
		
		/// RENDERING
		
		// Update all items in list to be drawn.
		//list.Draw();
		
		window.clear();
		
		//for(int i = 0; i < SIZE; i++) // Draw each node in list.
		//{
		//	window.draw(list.GetNodeAt(i)->rectangle);
		//}
		
		window.display();
	}

	return 0;
}
