// Bullet.h
// Class name: 			 Bullet
// Description of class: Bullet which travels in straight path and damages player.
// Date Created:		 June 12, 2019
// Last Modified:		 June 12, 2019
// Created by:			 Tommy Janna

#ifndef BULLET_H
#define BULLET_H

#include <chrono>
#include "../GameObject.h"
#include "../Point.h"
#include "../Game.h"

class Bullet : public GameObject
{
public:
    Bullet(Point _startPosition, Uint8 _direction);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;
    
private:
	Uint8 direction;
	Point mazePos;
	
	std::chrono::system_clock::time_point beginningTime;
    std::chrono::duration<double, milli> elapsedTime;
};

#endif
