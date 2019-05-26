// Game.h
// Class Name:			Game
// Class Description:	Game class which represents an instance of the game.
//						This class contains methods which initialize the SFML framework,
//						create a new window, handle the game loop,
//						handle input, load graphics, and draw to the screen.
// Date Created:		May 22, 2019
// Last Modified:		May 22, 2019
// Created by:			Tommy Janna

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "SceneManager.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

using namespace sf;

class Game
{
public:
	Game();
	~Game();
	
	void Run();
	
	void Input();
	void Update();
	void Draw();
	
	void Cleanup();
	
private:
	RenderWindow window;
};

#endif
