// Being.h
// Class name: 			 Being
// Description of class: Any being that has health, can attack, etc.
// Date Created:		 June 3, 2019
// Last Modified:		 June 3, 2019
// Created by:			 Tommy Janna

#ifndef BEING_H
#define BEING_H

#include "../GameObject.h"
#include "../Point.h"

class Being : public GameObject
{
public:
    Being(Point _position, Uint8 _layer, int _hp, int _ap, string _label);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;

protected:
    Point mazePos;

private:
	int hp;
	int ap;
};

#endif
