// Bullet.cpp
// Implementation of the Bullet class
// Date Created:	June 12, 2019
// Created by:		Tommy Janna

#include "Bullet.h"

Bullet::Bullet(Point _position, Uint8 _direction) :
                GameObject(_position.x * 40, _position.y * 40, 4, "Bullet")
{	
	direction = _direction;
	
	mazePos = _position;
	
	sprite.LoadTexture(std::string(PATH_PREFIX) + "assets/sprites/bullet.png", 2.5f);
	sprite.SetRotation(direction * 90);
	
	xPos = mazePos.x * 40;
	yPos = mazePos.y * 40;

	UpdatePosition();
		   
	// Mark start time to begin timer.
	beginningTime = chrono::system_clock::now();
}

void Bullet::Update()
{
	if(!Turret::freeze) // When player is hit, turrets and bullets freeze.
	{
		// Time since last bullet movement.
		elapsedTime = chrono::system_clock::now() - beginningTime;
		
		if(elapsedTime.count() >= 300) // 300 milliseconds between each movement
		{
			// Reset start time stamp.
			beginningTime = chrono::system_clock::now();
			
			if(direction == 0) // Right.
			{
				mazePos.x++;
			}
			
			else if(direction == 1) // Down.
			{
				mazePos.y++;
			}
			
			else if(direction == 2) // Left. 
			{
				mazePos.x--;
			}
			
			else if(direction == 3) // Up.
			{
				mazePos.y--;
			}
		}
		
		if(Maze::GetCell(mazePos.x, mazePos.y) % 2 == 1) // Over impassable cell
		{
			GameObject::objects->Delete(GameObject::objects->GetLink(this));
		}
		
		else if(Maze::GetCell(mazePos.x, mazePos.y) == 4) // Hitting player
		{
			// Freeze turrets and bullets.
			Turret::freeze = true;
			Player::SetInfoText("You have been destroyed by the\nforces of evil, Mike Wazowski.\nBetter luck next time...", 13);
		}
		
		// Update the absolute position.
		xPos = mazePos.x * 40;
		yPos = mazePos.y * 40;

		UpdatePosition();
		
	}

	return;
}

void Bullet::Destroy()
{
	return;
}

Drawable* Bullet::GetDrawable()
{
	return sprite.GetDrawable();
}



