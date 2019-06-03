// GameObject.h
// Class name: 			 GameObject
// Description of class: GameObject class which implements all necessary members for,
//                       objects in the game such as position, texture,
//                       and an abstract update function.
// Date Created:		 May 23, 2019
// Last Modified:		 May 23, 2019
// Created by:			 Tommy Janna

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics/Drawable.hpp>
#include "LinkedList.h"
#include "Sprite.h"

class LinkedList;

class GameObject
{
public:
	GameObject(int _x, int _y, Uint8 _layer, string _label);
	virtual ~GameObject();

	virtual void Update() = 0; // (= 0) makes this a pure virtual method, so Update() must be implemented.
	virtual void Destroy() = 0;
	virtual Drawable* GetDrawable() = 0;

	void UpdatePosition();

	static LinkedList* objects;

	Uint8 GetLayer();
	string GetLabel();

protected:
	int xPos, yPos;

	MySprite sprite;

private:
	Uint8 layer;

	string label;
};

#endif
