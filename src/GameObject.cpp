// GameObject.cpp
// Implementation of the GameObject class.
// Date Created:	May 23, 2019
// Created by:		Tommy Janna

#include "GameObject.h"

GameObject::GameObject(int _x, int _y, Uint8 _layer, string _label)
{
	xPos = _x;
	yPos = _y;

	layer = _layer;
	
	label = _label;
	
	objects->Add(this, objects->GetLast());
}

void GameObject::UpdatePosition()
{
	return sprite.SetPosition(xPos, yPos);
}

Uint8 GameObject::GetLayer()
{
	return layer;
}

string GameObject::GetLabel()
{
	return label;
}
