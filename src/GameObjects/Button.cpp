// Button.cpp
// Implementation of the Button class
// Date Created:	May 25, 2019
// Last Modified:	May 25, 2019
// Created by:		Tommy Janna

#include "Button.h"

Button::Button(int _x, int _y, int _width, int _height, Uint8 _layer, string _text, Uint8 _fontSize, std::function<void()> const& _event) : GameObject(_x, _y, _width, _height, _layer)
{
    _down = false;
    _timerRunning = false;

    event = _event;
    
    sprite.LoadRenderedText(_text, _fontSize);

    return;
}

/*Button::Button(SDL_Renderer* renderer, int x, int y, int width, int height, Uint8 layer, int fontSize, string text, function<void()> const& event, bool menuButton) : GameObject(x, y, width, height, layer, renderer, "Button + Text")
{
    _menuButton = menuButton;

    _x = x;
    _y = y;

    _event = event;

    _texture->_font = TTF_OpenFont("../assets/fonts/lilliputsteps.ttf", fontSize);

    if(_texture->_font == NULL)
    {
        printf("Error loading fonts... Error %s\n", TTF_GetError());
    }

    else
    {
        SDL_Color colour = {0xFF, 0xFF, 0xFF};

        _texture->LoadRenderedText(text, colour);
    }

    _buttonWidth = _texture->_width;
    _buttonHeight = _texture->_height;

    return;
}

Button::Button(SDL_Renderer* renderer, int x, int y, int width, int height, Uint8 layer, int fontSize, string font, string text, function<void()> const& event, bool menuButton) : GameObject(x, y, width, height, layer, renderer, "Button + Text")
{
    _menuButton = menuButton;

    _x = x;
    _y = y;

    _event = event;

    _texture->_font = TTF_OpenFont(font.c_str(), fontSize);

    if(_texture->_font == NULL)
    {
        printf("Error loading fonts... Error %s\n", TTF_GetError());
    }

    else
    {
        SDL_Color colour = {0xFF, 0xFF, 0xFF};

        _texture->LoadRenderedText(text, colour);
    }

    _buttonWidth = _texture->_width;
    _buttonHeight = _texture->_height;

    return;
}

Button::~Button()
{

}

void Button::Update()
{
    bool inside = true; // Innocent until proven guilty :)
    bool timeCheck = true;

    // Get mouse pos.
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    // There is a timer between each button press to avoid,
    // accidental double clicking of seperate buttons on a trackpad.
    if(_timerRunning)
    {
        _elapsedTime = chrono::system_clock::now() - _beginningTime;
        if(_elapsedTime.count() < 200) // 200 milliseconds between each push
        {
            timeCheck = false;
        }
    }

    if(_show && timeCheck) // Timer must be complete.
    {
        // Check mouse pos with button boundaries.
        if(mouseX < _x)
        {
            inside = false;
        }

        else if(mouseX > _x + _buttonWidth)
        {
            inside = false;
        }

        else if(mouseY < _y)
        {
            inside = false;
        }

        else if(mouseY > _y + _buttonHeight)
        {
            inside = false;
        }

        if(!inside)
        {
            _down = false;
            _texture->SetColor(255, 255, 255);
        }

        else
        {
            if(Game::_mouseInput[0]) // Mouse over.
            {
                _texture->SetColor(150, 255, 0);
            }

            if(Game::_mouseInput[1]) // Mouse down.
            {
                _down = true;
                _texture->SetColor(100, 255, 0);
            }

            if(Game::_mouseInput[2]) // Mouse up.
            {
                if(_down)
                {
                    // Start timer between button presses.
                    _beginningTime = chrono::system_clock::now();
                    _timerRunning = true;

                    _down = false;

                    _texture->SetColor(255, 255, 0);
                    
                    if(_menuButton)
                    {
                        Menu::Destroy();
                    }

                    // Fire button's _event action.
                    _event();
                }
            }
        }
    }

    return;
}*/

Button::~Button()
{
}

void Button::Update()
{
}

Drawable* Button::GetDrawable()
{
	return sprite.GetDrawable();
}

void Button::Destroy()
{
}
