// Sprite.cpp
// Implementation of the MySprite class.
// Date Created:	  May 25, 2019
// Last Modified:	  May 25, 2019
// Created by:		  Tommy Janna

#include "Sprite.h"

void MySprite::LoadTexture(string _path, float _scale)
{
	texture.loadFromFile(_path);

	// Disable anti-aliasing to display true pixel data.
	texture.setSmooth(false);

	sprite.setTexture(texture);

	sprite.setScale(_scale, _scale);

	drawable = &sprite;

	return;
}

void MySprite::LoadRenderedText(string _text, Uint8 _fontSize)
{
#ifndef _WIN32
	font.loadFromFile("../assets/fonts/Early-Gameboy.ttf");
#else
    font.loadFromFile("assets/fonts/Early-Gameboy.ttf");
#endif
	text.setFont(font);
	text.setString(_text);
	text.setCharacterSize(_fontSize);
	text.setFillColor(Color::Black);

	width = text.getLocalBounds().width;
	height = text.getLocalBounds().height;

	drawable = &text;
	return;
}

void MySprite::SetColor(Color _colour)
{
	text.setFillColor(_colour);
	return;
}

void MySprite::SetPosition(int _x, int _y)
{
	sprite.setPosition(_x, _y);
	text.setPosition(_x, _y);

	return;
}

int MySprite::GetWidth()
{
	return width;
}

int MySprite::GetHeight()
{
	return height;
}

Drawable* MySprite::GetDrawable()
{
	return drawable;
}
