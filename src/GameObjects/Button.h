// Button.h
// Class name: 			 Button
// Description of class: It's a button.
// Date Created:		 May 25, 2019
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
    Button(int _x, int _y, Uint8 _layer, string _text, Uint8 _fontSize, string _label, std::function<void()> const& _event);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;

private:
    std::chrono::system_clock::time_point beginningTime; // Time of last button pressed.
    std::chrono::duration<double, milli> elapsedTime; // Time between last button pressed and now().
    bool timerRunning;

    bool down; // Is button being held?

    function<void()> event; // Function that will fire when the button is pushed.
};

#endif
