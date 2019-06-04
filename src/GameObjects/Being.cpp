// Being.cpp
// Implementation of the Being class
// Date Created:	June 3, 2019
// Last Modified:	June 3, 2019
// Created by:		Tommy Janna

#include "Being.h"

Being::Being(int _x, int _y, Uint8 _layer, int _hp, int _ap, string _label) : GameObject(_x, _y, _layer, _label)
{
	hp = _hp;
	ap = _ap;
}

void Being::Update()
{
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


