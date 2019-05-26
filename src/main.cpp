// main.cpp
// Project Title:		Maze Game
// Project Description:	A program that builds a pre-defined maze with keys
//						and locked doors, and gives the user the 
//						option to have the maze be solved by the 
//						computer, or play an adventure/RPG
//						like interactive mode with monsters.
// Date Created:		May 22, 2019
// Last Modified:		May 22, 2019
// Created by:			Tommy Janna

#include "Game.h"

int main()
{
	Game myGame;
	
	// Begin game loop.
	myGame.Run();
	
	return 0;
}
