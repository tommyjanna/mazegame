// Sprite.cpp
// Implementation of the MySprite class.
// Date Created:	  May 25, 2019
// Created by:		  Tommy Janna

#include "Sprite.h"

void MySprite::LoadTexture(string _path, float _scale)
{
	texture.loadFromFile(_path);

	// Disable anti-aliasing to display true pixel data.
	texture.setSmooth(false);

	sprite.setTexture(texture);
	sprite.setScale(_scale, _scale);
	
	// Current drawable is sprite, not text.
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

	// Used for determining border for a button.
	width = text.getLocalBounds().width;
	height = text.getLocalBounds().height;

	// Current drawable is text, not sprite.
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
	sprite.setPosition(_x + xOffset, _y + yOffset);
	text.setPosition(_x, _y);

	return;
}

void MySprite::SetRotation(int _angle)
{
	sprite.setRotation(_angle);
	
	// Because sfml rotates from top left, adjust position offset
	// to imitate rotation from a central pivot.
	if(_angle == 0)
	{
		xOffset = 0;
		yOffset = 0;
	}
	
	else if(_angle <= 90)
	{
		xOffset = 40;
		yOffset = 0;
	}
	
	else if(_angle <= 180)
	{
		xOffset = 40;
		yOffset = 40;
	}
	
	else if(_angle <= 270)
	{
		xOffset = 0;
		yOffset	= 40;
	}
	
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
