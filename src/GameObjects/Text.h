// Text.h
// Class name: 			 MyText
// Description of class: It's a text field.
// Date Created:		 May 25, 2019
// Created by:			 Tommy Janna

#ifndef TEXT_H
#define TEXT_H

#include "../GameObject.h"

class MyText : public GameObject
{
public:
    MyText(int _x, int _y, Uint8 _layer, string _text, Uint8 _fontSize, string _label);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;
    
    void UpdateText(string _text, int _fontSize);
};

#endif
