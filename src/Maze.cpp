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
	Wall* wall = new Wall(20, 20, 1);
	GameObject::objects.Add(wall, GameObject::objects.GetLast());
}
