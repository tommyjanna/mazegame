// Sprite.h
// Class Name:		  MySprite
// Class Description: Sprite wrapper class for sf::Texture and sf::Text
// Date Created:	  May 25, 2019
// Last Modified:	  May 25, 2019
// Created by:		  Tommy Janna

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class MySprite
{
public:

    void LoadTexture(string _path, int _scale);
    void LoadRenderedText(string _text, Uint8 _fontSize);

    void SetColor(Color _colour);
    void SetPosition(int _x, int _y);

    int GetWidth();
    int GetHeight();

	Drawable* GetDrawable();

private:

    Text text;
    Texture texture;
    Font font;
    Sprite sprite;

    int width;
    int height;

    Drawable* drawable;
};

#endif
