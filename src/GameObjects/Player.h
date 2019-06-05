// Player.h
// Class name: 			 Player
// Description of class: User controlled being, who's goal is to reach
//						 the end of the maze without being killed.
// Date Created:		 June 3, 2019
// Last Modified:		 June 3, 2019
// Created by:			 Tommy Janna

#ifndef PLAYER_H
#define PLAYER_H

#include "Being.h"
#include "../Game.h"

class Player : public Being
{
public:
    Player(Point _position, Uint8 _layer, int _hp, int _ap, string _label);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;
};

#endif

