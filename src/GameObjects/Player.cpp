// Player.cpp
// Implementation of the Player class
// Date Created:	June 3, 2019
// Last Modified:	June 3, 2019
// Created by:		Tommy Janna

#include "Player.h"
#include <iostream>

Player::Player(Point _position, Uint8 _layer, int _hp, int _ap, string _label) :Being(_position, _layer, _hp, _ap, _label)
{
	sprite.LoadTexture(std::string(PATH_PREFIX) + "assets/sprites/mike.png", 2.5f);
	
	hasKey = false;
	
	infoText = new MyText(220, 620, 4, "Welcome to the dungeon,\nMike Wazowski", 15, "Info Text");
}

void Player::Update()
{
	if(!(mazePos.x == 13 && mazePos.y == 13))
	{
		if(Game::keyboardState[0]) // Up
		{
			if(Maze::GetCell(mazePos.x, mazePos.y - 1) % 2 == 0) // Even numbers are movable
			{
				mazePos.y--;

				if(Maze::GetCell(mazePos.x, mazePos.y) == 2 && !hasKey) // On key
				{
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key"));

					MyImage* keyCollected = new MyImage(20, 620, 2, std::string(std::string(PATH_PREFIX)) + "assets/sprites/key.png", 3.5f, "Key Collected");
					hasKey = true;
					
					Maze::SetCell(mazePos.x, mazePos.y, 0);
				}
			}
			
			else if(Maze::GetCell(mazePos.x, mazePos.y - 1) == 3 && hasKey)
			{
				mazePos.x++;
				
				GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Door"));
				GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key Collected"));
				hasKey = false;
				
				Maze::SetCell(mazePos.x, mazePos.y, 0);
			}

			Game::keyboardState[0] = false;
		}

		else if(Game::keyboardState[1]) // Down
		{
			if(Maze::GetCell(mazePos.x, mazePos.y + 1) % 2 == 0)
			{
				mazePos.y++;
			   
				if(Maze::GetCell(mazePos.x, mazePos.y) == 2 && !hasKey)
				{
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key"));

					MyImage* keyCollected = new MyImage(20, 620, 2, std::string(std::string(PATH_PREFIX)) + "assets/sprites/key.png", 3.5f, "Key Collected");
					hasKey = true;

					Maze::SetCell(mazePos.x, mazePos.y, 0);
				}
			}
			
			else if(Maze::GetCell(mazePos.x, mazePos.y + 1) == 3 && hasKey)
			{
				mazePos.x++;
				
				GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Door"));
				GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key Collected"));
				hasKey = false;
				
				Maze::SetCell(mazePos.x, mazePos.y, 0);
			}

			Game::keyboardState[1] = false;
		}

		else if(Game::keyboardState[2]) // Left
		{
			if(Maze::GetCell(mazePos.x - 1, mazePos.y) % 2 == 0)
			{
				mazePos.x--;
				
				if(Maze::GetCell(mazePos.x, mazePos.y) == 2 && !hasKey)
				{
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key"));

					MyImage* keyCollected = new MyImage(20, 620, 2, std::string(std::string(PATH_PREFIX)) + "assets/sprites/key.png", 3.5f, "Key Collected");
					hasKey = true;

					Maze::SetCell(mazePos.x, mazePos.y, 0);
				}
			}
			
			else if(Maze::GetCell(mazePos.x - 1, mazePos.y) == 3 && hasKey)
			{
				mazePos.x++;
				
				GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Door"));
				GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key Collected"));
				hasKey = false;
				
				Maze::SetCell(mazePos.x, mazePos.y, 0);
			}

			Game::keyboardState[2] = false;
		}

		else if(Game::keyboardState[3]) // Right
		{
			if(Maze::GetCell(mazePos.x + 1, mazePos.y) % 2 == 0)
			{
				mazePos.x++;
				
				if(Maze::GetCell(mazePos.x, mazePos.y) == 2 && !hasKey)
				{
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key"));

					MyImage* keyCollected = new MyImage(20, 620, 2, std::string(std::string(PATH_PREFIX)) + "assets/sprites/key.png", 3.5f, "Key Collected");
					hasKey = true;
					
					Maze::SetCell(mazePos.x, mazePos.y, 0);
				}
			}
			
			else if(Maze::GetCell(mazePos.x + 1, mazePos.y) == 3 && hasKey)
			{
				mazePos.x++;
				
				GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Door"));
				GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key Collected"));
				hasKey = false;
				
				Maze::SetCell(mazePos.x, mazePos.y, 0);
			}

			Game::keyboardState[3] = false;
		}
	}
	
	else
	{
		infoText->UpdateText("You win!\nCongratulations Mike!", 15);
	}

    Being::Update();
	return;
}

void Player::Destroy()
{
	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Info Text"));
	return;
}

Drawable* Player::GetDrawable()
{
	return sprite.GetDrawable();
}


