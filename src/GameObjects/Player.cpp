// Player.cpp
// Implementation of the Player class
// Date Created:	June 3, 2019
// Created by:		Tommy Janna

#include "Player.h"

// Declare static members.
MyText* Player::infoText;
bool Player::interacting;

Player::Player(Point _position, Uint8 _layer, string _label) : GameObject(_position.x * 40, _position.y * 40, _layer, _label)
{
	mazePos = _position;
	
	sprite.LoadTexture(std::string(PATH_PREFIX) + "assets/sprites/mike.png", 2.5f);
	
	hasKey = false;
	interacting = false;
	
	infoText = new MyText(220, 620, 4, "Welcome to the dungeon,\nMike Wazowski", 15, "Info Text");
}

void Player::Update()
{
	if(!Turret::freeze && !interacting) // Is the player allowed to move?
	{
		if(!(mazePos.x == 13 && mazePos.y == 13)) // Is player at end?
		{
			Uint8 movingCell;
			
			if(Game::keyboardState[0]) // Up
			{
				movingCell = Maze::GetCell(mazePos.x, mazePos.y - 1);
				
				if(movingCell % 2 == 0) // Even numbers are movable
				{
					if(movingCell == 6) // Riddler
					{
						// Begin riddler interaction.
						// Don't allow player to move during this time.
						Maze::GetRiddler()->Interact("start");
						interacting = true;
					}
					
					else
					{
						// Regular movement.
						Maze::SetCell(mazePos.x, mazePos.y, 0);
						mazePos.y--;

						if(movingCell == 2 && !hasKey) // On key
						{
							// Delete key from map, and add the icon to inventory.
							GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key"));
							MyImage* keyCollected = new MyImage(20, 620, 2, std::string(PATH_PREFIX) + "assets/sprites/key.png", 3.5f, "Key Collected");
							hasKey = true;
							
							// Reset the tile to just a regular space.
							Maze::SetCell(mazePos.x, mazePos.y, 0);
							infoText->UpdateText("You just collected a key!\nThis could be useful for some door\naround here...", 15);
						}
						
						else
						{
							// Set current cell to "player" (4)
							Maze::SetCell(mazePos.x, mazePos.y, 4);
						}
					}
				}
				
				else if(Maze::GetCell(mazePos.x, mazePos.y - 1) == 3 && hasKey) // Moving into door and has key?
				{
					Maze::SetCell(mazePos.x, mazePos.y, 0);
					Maze::SetCell(mazePos.x, --mazePos.y, 4);
					
					// Remove door from map and key from inventory.
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Door"));
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key Collected"));
					hasKey = false;
					
					Maze::SetCell(mazePos.x, mazePos.y, 0);
					infoText->UpdateText("A perfect fit! The\ndoor swings OPEN!", 20);
				}

				Game::keyboardState[0] = false;
			}

			else if(Game::keyboardState[1]) // Down
			{
				movingCell = Maze::GetCell(mazePos.x, mazePos.y + 1);
				
				if(movingCell % 2 == 0)
				{
					if(movingCell == 6)
					{
						Maze::GetRiddler()->Interact("start");
						interacting = true;
					}
					
					else
					{
						Maze::SetCell(mazePos.x, mazePos.y, 0);
						mazePos.y++;
					   
						if(movingCell == 2 && !hasKey)
						{
							GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key"));

							MyImage* keyCollected = new MyImage(20, 620, 2, std::string(PATH_PREFIX) + "assets/sprites/key.png", 3.5f, "Key Collected");
							hasKey = true;

							Maze::SetCell(mazePos.x, mazePos.y, 0);
							infoText->UpdateText("You just collected a key!\nThis could be useful for\nsome door around here...", 15);
						}
						
						else
						{
							Maze::SetCell(mazePos.x, mazePos.y, 4);
						}
					}
				}
				
				else if(Maze::GetCell(mazePos.x, mazePos.y + 1) == 3 && hasKey)
				{
					Maze::SetCell(mazePos.x, mazePos.y, 0);
					Maze::SetCell(mazePos.x, ++mazePos.y, 4);
					
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Door"));
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key Collected"));
					hasKey = false;
					
					Maze::SetCell(mazePos.x, mazePos.y, 0);
					infoText->UpdateText("A perfect fit! The\ndoor swings OPEN!", 20);
				}

				Game::keyboardState[1] = false;
			}

			else if(Game::keyboardState[2]) // Left
			{
				movingCell = Maze::GetCell(mazePos.x - 1, mazePos.y);
				
				if(movingCell % 2 == 0)
				{
					if(movingCell == 6)
					{
						Maze::GetRiddler()->Interact("start");
						interacting = true;
					}
					
					else
					{
						Maze::SetCell(mazePos.x, mazePos.y, 0);
						mazePos.x--;
						
						if(movingCell == 2 && !hasKey)
						{
							GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key"));

							MyImage* keyCollected = new MyImage(20, 620, 2, std::string(PATH_PREFIX) + "assets/sprites/key.png", 3.5f, "Key Collected");
							hasKey = true;

							Maze::SetCell(mazePos.x, mazePos.y, 0);
							infoText->UpdateText("You just collected a key!\nThis could be useful for some door\naround here...", 15);
						}
						
						else
						{
							Maze::SetCell(mazePos.x, mazePos.y, 4);
						}
					}
				}
				
				else if(Maze::GetCell(mazePos.x - 1, mazePos.y) == 3 && hasKey)
				{
					Maze::SetCell(mazePos.x, mazePos.y, 0);
					Maze::SetCell(--mazePos.x, mazePos.y, 4);
					
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Door"));
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key Collected"));
					hasKey = false;
					
					Maze::SetCell(mazePos.x, mazePos.y, 0);
					infoText->UpdateText("A perfect fit! The\ndoor swings OPEN!", 20);
				}

				Game::keyboardState[2] = false;
			}

			else if(Game::keyboardState[3]) // Right
			{
				movingCell = Maze::GetCell(mazePos.x + 1, mazePos.y);
				
				if(movingCell % 2 == 0)
				{
					if(movingCell == 6)
					{
						Maze::GetRiddler()->Interact("start");
						interacting = true;
					}
					
					else
					{
						Maze::SetCell(mazePos.x, mazePos.y, 0);
						mazePos.x++;
						
						if(movingCell == 2 && !hasKey)
						{
							GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key"));

							MyImage* keyCollected = new MyImage(20, 620, 2, std::string(PATH_PREFIX) + "assets/sprites/key.png", 3.5f, "Key Collected");
							hasKey = true;
							
							Maze::SetCell(mazePos.x, mazePos.y, 0);
							
							infoText->UpdateText("You just collected a key!\nThis could be useful for some door\naround here...", 15);
						}
						
						else
						{
							Maze::SetCell(mazePos.x, mazePos.y, 4);
						}
					}
				}
				
				else if(Maze::GetCell(mazePos.x + 1, mazePos.y) == 3 && hasKey)
				{
					Maze::SetCell(mazePos.x, mazePos.y, 0);
					Maze::SetCell(++mazePos.x, mazePos.y, 5);
					
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Door"));
					GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key Collected"));
					hasKey = false;
					
					Maze::SetCell(mazePos.x, mazePos.y, 0);
					infoText->UpdateText("A perfect fit! The\ndoor swings OPEN!", 20);
				}

				Game::keyboardState[3] = false;
			}
		}
		
		else // Player reached end of maze.
		{
			infoText->UpdateText("You win!\nCongratulations Mike!", 15);
		}
	}

	// Update player's absolute position.
	xPos = mazePos.x * 40;
	yPos = mazePos.y * 40;

	UpdatePosition();
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

void Player::SetInfoText(string _text, Uint8 _fontSize)
{
	infoText->UpdateText(_text, _fontSize);
	return;
}


