// Image.h
// Class name: 			 MyImage
// Description of class: Simple GameObject that displays given image.
// Date Created:		 May 27, 2019
// Last Modified:		 May 27, 2019
// Created by:			 Tommy Janna

#ifndef IMAGE_H
#define IMAGE_H

#include "../GameObject.h"

class MyImage : public GameObject
{
public:
    MyImage(int _x, int _y, Uint8 _layer, string _path, string _label);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;
};

#endif
