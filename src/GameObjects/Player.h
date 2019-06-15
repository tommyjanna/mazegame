// Player.h
// Class name: 			 Player
// Description of class: User controlled being, who's goal is to reach
//						 the end of the maze without being killed.
// Date Created:		 June 3, 2019
// Last Modified:		 June 3, 2019
// Created by:			 Tommy Janna

#ifndef PLAYER_H
#define PLAYER_H

#include "Turret.h"
#include "../Game.h"
#include "../GameObject.h"

class Player : public GameObject
{
public:
    Player(Point _position, Uint8 _layer, string _label);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;

    static void SetInfoText(string _text, Uint8 _fontSize);
	static bool interacting;

private:
	Point mazePos;
	bool hasKey;
	
	static MyText* infoText;
};

#endif
