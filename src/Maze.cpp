// Maze.cpp
// Implementation of the Maze class
// Date Created:	May 27, 2019
// Last Modified:	May 27, 2019
// Created by:		Tommy Janna

#include "Maze.h"

Maze::Maze()
{
	// 0 - Space
	// 1 - Wall

	for(int i = 0; i < 15; i++)
    {
        Wall* wall = new Wall(40 * i, 0, 1);
        GameObject::objects.Add(wall, GameObject::objects.GetLast());

        wall = new Wall(40 * i, 560, 1);
        GameObject::objects.Add(wall, GameObject::objects.GetLast());

    }
}
