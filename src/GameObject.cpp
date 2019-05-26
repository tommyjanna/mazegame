// GameObject.cpp
// Implementation of the GameObject class.
// Date Created:	May 23, 2019
// Last Modified:	May 23, 2019
// Created by:		Tommy Janna

#include "GameObject.h"

GameObject::GameObject(int _x, int _y, int _width, int _height, Uint8 _layer)
{
	xPos = _x;
	yPos = _y;
	
	width = _width;
	height = _height;
	
	layer = _layer;
}

GameObject::~GameObject()
{
}

Uint8 GameObject::GetLayer()
{
	return layer;
}

Drawable* GameObject::GetDrawable()
{
	return GetDrawable();
}
