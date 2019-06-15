// Image.cpp
// Implementation of the Image class
// Date Created:	May 27, 2019
// Created by:		Tommy Janna

#include "Image.h"

MyImage::MyImage(int _x, int _y, Uint8 _layer, string _path, string _label) : GameObject(_x, _y, _layer, _label)
{
	sprite.LoadTexture(_path, 2.5f);
}

MyImage::MyImage(int _x, int _y, Uint8 _layer, string _path, int _scale, string _label) : GameObject(_x, _y, _layer, _label)
{
	sprite.LoadTexture(_path, _scale);
}

void MyImage::Update()
{
	return;
}

void MyImage::Destroy()
{
	return;
}

Drawable* MyImage::GetDrawable()
{
	return sprite.GetDrawable();
}

