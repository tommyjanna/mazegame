// Riddler.h
// Class name: 			 Riddler
// Description of class: Interact with player and asks them riddles.
//						 If the player gets 2 of 3 right, the riddler is defeated,
//						 otherwise the player is defeated.
// Date Created:		 June 13, 2019
// Last Modified:		 June 13, 2019
// Created by:			 Tommy Janna

#ifndef RIDDLER_H
#define RIDDLER_H

#include "../Game.h"
#include "../GameObject.h"
#include "../Point.h"

class Riddler : public GameObject
{
public:
    Riddler(Point _position, Uint8 _layer, string _label);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;
    
    void Interact(string _action);

private:
	Point mazePos;
	
	int currentPanel;
};

#endif
