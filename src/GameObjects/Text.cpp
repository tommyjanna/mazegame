// Text.cpp
// Implementation of the MyText class
// Date Created:	May 25, 2019
// Last Modified:	May 25, 2019
// Created by:		Tommy Janna

#include "Text.h"

MyText::MyText(int _x, int _y, Uint8 _layer, string _text, Uint8 _fontSize) : GameObject(_x, _y, _layer)
{
    sprite.LoadRenderedText(_text, _fontSize);
}

void MyText::Update()
{
	return;
}

void MyText::Destroy()
{
	return;
}

Drawable* MyText::GetDrawable()
{
	return sprite.GetDrawable();
}
