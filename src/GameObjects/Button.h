// GameObject.h
// Class name: 			 Button
// Description of class: It's a button.
// Date Created:		 May 25, 2019
// Last Modified:		 May 25, 2019
// Created by:			 Tommy Janna

#ifndef BUTTON_H
#define BUTTON_H

#include "../GameObject.h"
#include <functional>
#include <chrono>

using namespace std;

class Button : public GameObject
{
public:
    Button(int _x, int _y, int _width, int _height, Uint8 _layer, string _path, Uint8 _fontSize, std::function<void()> const& _event);
    ~Button();

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;

private:

    chrono::system_clock::time_point _beginningTime;
    chrono::duration<double, milli> _elapsedTime;
    bool _timerRunning;

    bool _down;
    
    MySprite sprite;

    // Function that will fire when the button is pushed.
    function<void()> event;
};

#endif
