// Turret.cpp
// Implementation of the Turret class
// Date Created:	June 12, 2019
// Created by:		Tommy Janna

#include "Turret.h"

// Declare static members.
bool Turret::freeze;

Turret::Turret(Point _position, Uint8 _direction) :
                GameObject(_position.x * 40, _position.y * 40, 3, "Turret")
{	
	direction = _direction;
	
	xPos = _position.x * 40;
	yPos = _position.y * 40;
	
	mazePos = _position;
	
	UpdatePosition();
	
	sprite.LoadTexture(std::string(PATH_PREFIX) + "assets/sprites/turret.png", 2.5f);
	sprite.SetRotation(direction * 90);
                    
	// Mark start time to begin timer and fire first bullet.
	beginningTime = chrono::system_clock::now();
	Bullet* b = new Bullet(mazePos, direction);
}

void Turret::Update()
{
	if(!freeze) // When player is hit, turrets and bullets freeze.
	{
		elapsedTime = chrono::system_clock::now() - beginningTime;
		if(elapsedTime.count() >= 2000) // 2000 milliseconds between each fire
		{
			// Reset start time stamp.
			beginningTime = chrono::system_clock::now();
			
			// Fire bullet.
			Bullet* b = new Bullet(mazePos, direction);
		}
	}

	return;
}

void Turret::Destroy()
{
	return;
}

Drawable* Turret::GetDrawable()
{
	return sprite.GetDrawable();
}


