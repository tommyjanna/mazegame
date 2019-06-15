// Riddler.cpp
// Implementation of the Riddler class
// Date Created:	June 13, 2019
// Last Modified:	June 13, 2019
// Created by:		Tommy Janna

#include "Riddler.h"

Riddler::Riddler(Point _position, Uint8 _layer, string _label) : GameObject(_position.x * 40, _position.y * 40, _layer, _label)
{
	mazePos = _position;
	
	xPos = mazePos.x * 40;
	yPos = mazePos.y * 40;
	
	sprite.LoadTexture(std::string(PATH_PREFIX) + "assets/sprites/james_p_sullivan.png", 2.5f);
	
	UpdatePosition();
}

void Riddler::Update()
{
	if(interacting)
	{
		Player::SetInfoText("Mike Wazowski, I am\nJames P. Sullivan.", 15);
	}
	
	return;
}

void Riddler::Destroy()
{
	return;
}

Drawable* Riddler::GetDrawable()
{
	return sprite.GetDrawable();
}
