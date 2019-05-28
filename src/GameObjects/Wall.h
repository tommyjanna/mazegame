// Wall.h
// Class name: 			 Wall
// Description of class: Simple GameObject that displays a wall.
// Date Created:		 May 27, 2019
// Last Modified:		 May 27, 2019
// Created by:			 Tommy Janna

#ifndef WALL_H
#define WALL_H

#include "../GameObject.h"

class Wall : public GameObject
{
public:
    Wall(int _x, int _y, Uint8 _layer);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;
};

#endif
