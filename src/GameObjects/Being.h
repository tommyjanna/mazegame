// Being.h
// Class name: 			 Being
// Description of class: Any being that has health, can attack, etc.
// Date Created:		 June 3, 2019
// Last Modified:		 June 3, 2019
// Created by:			 Tommy Janna

#ifndef BEING_H
#define BEING_H

#include "../GameObject.h"

class Being : public GameObject
{
public:
    Being(int _x, int _y, Uint8 _layer, int _hp, int _ap, string _label);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;

private:
	int hp;
	int ap;
};

#endif
