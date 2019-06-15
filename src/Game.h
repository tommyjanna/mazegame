// Game.h
// Class Name:			Game
// Class Description:	Game class which represents an instance of the game.
//						This class contains methods which initialize the SFML framework,
//						create a new window, handle the game loop,
//						handle input, load graphics, and draw to the screen.
// Date Created:		May 22, 2019
// Created by:			Tommy Janna

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "SceneManager.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 720

class Game
{
public:
	Game();

	void Run();

	void Input();
	void Update();
	void Draw();

	static Vector2i mousePos; // Coordinates of mouse position relative to window.
	static bool mouseState[2]; // Holds pressed or released for left and right mouse buttons.
	static bool keyboardState[4]; // Holds pressed or released for up, down, left, right.

private:
	RenderWindow window;

	bool mouseEventOccur;
};

#endif
