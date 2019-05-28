// Wall.cpp
// Implementation of the Wall class
// Date Created:	May 27, 2019
// Last Modified:	May 27, 2019
// Created by:		Tommy Janna

#include "Wall.h"

Wall::Wall(int _x, int _y, Uint8 _layer) : GameObject(_x, _y, _layer)
{
#ifndef _WIN32
    sprite.LoadTexture("../assets/sprites/wall.png");
#else
    sprite.LoadTexture("assets/sprites/wall.png");
#endif
}

void Wall::Update()
{
	return;
}

void Wall::Destroy()
{
	return;
}

Drawable* Wall::GetDrawable()
{
	return sprite.GetDrawable();
}

