// Player.cpp
// Implementation of the Player class
// Date Created:	June 3, 2019
// Last Modified:	June 3, 2019
// Created by:		Tommy Janna

#include "Player.h"
#include <iostream>

Player::Player(Point _position, Uint8 _layer, int _hp, int _ap, string _label) :Being(_position, _layer, _hp, _ap, _label)
{
#ifndef _WIN32
	sprite.LoadTexture("../assets/sprites/player.png", 2.5f);
#else
	sprite.LoadTexture("assets/sprites/player.png", 2.5f);
#endif
}

void Player::Update()
{
    if(Game::keyboardState[0]) // Up
    {
        mazePos.y--;
        Game::keyboardState[0] = false;
    }

    else if(Game::keyboardState[1]) // Down
    {
        mazePos.y++;
        Game::keyboardState[1] = false;
    }

    else if(Game::keyboardState[2]) // Left
    {
        mazePos.x--;
        Game::keyboardState[2] = false;
    }

    else if(Game::keyboardState[3]) // Right
    {
        mazePos.x++;
        Game::keyboardState[3] = false;
    }

    Being::Update();
	return;
}

void Player::Destroy()
{
	return;
}

Drawable* Player::GetDrawable()
{
	return sprite.GetDrawable();
}


