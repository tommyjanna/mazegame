// Turret.h
// Class name: 			 Turret
// Description of class: Fires bullets in a straight line which damage the player.
// Date Created:		 June 12, 2019
// Last Modified:		 June 12, 2019
// Created by:			 Tommy Janna

#ifndef TURRET_H
#define TURRET_H

#include <chrono>
#include "../GameObject.h"
#include "../Point.h"
#include "../Game.h"
#include "Bullet.h"

class Turret : public GameObject
{
public:
    Turret(Point _position, Uint8 _direction);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;
    
    static bool freeze;
    
private:
	Uint8 direction;
	Point mazePos;
	
	std::chrono::system_clock::time_point beginningTime;
    std::chrono::duration<double, milli> elapsedTime;
};

#endif
