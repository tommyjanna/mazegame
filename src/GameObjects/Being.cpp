// Being.cpp
// Implementation of the Being class
// Date Created:	June 3, 2019
// Last Modified:	June 3, 2019
// Created by:		Tommy Janna

#include "Being.h"
#include <iostream>

Being::Being(Point _position, Uint8 _layer, int _hp, int _ap, string _label) :
                GameObject(_position.x * 40, _position.y * 40, _layer, _label)
{
	mazePos = _position;

	hp = _hp;
	ap = _ap;
}

void Being::Update()
{
	xPos = mazePos.x * 40;
	yPos = mazePos.y * 40;

	UpdatePosition();
	return;
}

void Being::Destroy()
{
	return;
}

Drawable* Being::GetDrawable()
{
	return sprite.GetDrawable();
}


