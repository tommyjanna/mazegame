// Button.cpp
// Implementation of the Button class
// Date Created:	May 25, 2019
// Last Modified:	May 25, 2019
// Created by:		Tommy Janna

#include "Button.h"

Button::Button(int _x, int _y, Uint8 _layer, string _text, Uint8 _fontSize, std::function<void()> const& _event) : GameObject(_x, _y, _layer)
{
    down = false;
    timerRunning = false;

    event = _event;
    
    sprite.LoadRenderedText(_text, _fontSize);
}

void Button::Update()
{
    bool timeCheck = true;

    // There is a timer between each button press to avoid,
    // accidental double clicking of seperate buttons on a trackpad.
    if(timerRunning)
    {
        _elapsedTime = chrono::system_clock::now() - _beginningTime;
        if(_elapsedTime.count() < 50) // 50 milliseconds between each push
        {
            timeCheck = false;
        }
    }

    if(timeCheck) // Timer must be complete.
    {
        // Check mouse pos with button boundaries.
        if((Game::mousePos.x > xPos - 10 && Game::mousePos.x < xPos + 10 + sprite.GetWidth()) &&
			(Game::mousePos.y > yPos - 20 && Game::mousePos.y < yPos + 20 + sprite.GetHeight()))
        {
            
            if(Game::mouseState[0]) // Mouse down.
            {
				down = true;
            }

			if(down)
			{
				if(Game::mouseState[1]) // Mouse up.
				{
                    // Start timer between button presses.
                    _beginningTime = chrono::system_clock::now();
                    timerRunning = true;

                    down = false;
                    
                    // Purple
                    sprite.SetColor(Color(86, 63, 98));
                    
                    // Fire button's _event action.
                    event();
                }
                
                else
                {
					// Dark purple
					sprite.SetColor(Color(58, 41, 66));
				}
            }

            else // Mouse over.
            {
				down = false;
				sprite.SetColor(Color(86, 63, 98));
            }
        }


        else
        {
			down = false;
            sprite.SetColor(Color::Black);
        }
    }

    return;
}

Drawable* Button::GetDrawable()
{
	return sprite.GetDrawable();
}

void Button::Destroy()
{
}
