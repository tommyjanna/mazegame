// Button.h
// Class name: 			 Button
// Description of class: It's a button.
// Date Created:		 May 25, 2019
// Last Modified:		 May 25, 2019
// Created by:			 Tommy Janna

#ifndef BUTTON_H
#define BUTTON_H

#include <functional>
#include <chrono>
#include <SFML/Window/Mouse.hpp>
#include "../GameObject.h"
#include "../Game.h"

class Button : public GameObject
{
public:
    Button(int _x, int _y, Uint8 _layer, string _text, Uint8 _fontSize, std::function<void()> const& _event);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;

private:

    std::chrono::system_clock::time_point _beginningTime;
    std::chrono::duration<double, milli> _elapsedTime;
    bool timerRunning;

    bool down;
    
    // Function that will fire when the button is pushed.
    function<void()> event;
};

#endif
