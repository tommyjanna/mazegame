// Maze.cpp
// Implementation of the Maze class
// Date Created:	May 27, 2019
// Last Modified:	May 27, 2019
// Created by:		Tommy Janna

#include "Maze.h"

Maze::Maze(bool _autoSolver) : GameObject(0, 0, 0, "Maze")
{
	// 0 - Space
	// 1 - Wall
	// 2 - Key
	// 3 - Door

	Uint8 tempMaze[15][15] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
							   { 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
							   { 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
							   { 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1 },
							   { 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
							   { 1, 0, 1, 0, 1, 2, 1, 0, 1, 1, 1, 0, 1, 0, 1 },
							   { 1, 0, 1, 0, 1, 1, 1, 0, 3, 0, 1, 1, 1, 0, 1 },
							   { 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1 },
							   { 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
							   { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
							   { 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
							   { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
							   { 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1 },
							   { 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1 },
							   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
#ifndef _WIN32
                pathPrefix = "../";
#else
                pathPrefix = "";
#endif

	for(int i = 0; i < 15; i++)
	{
		for(int j = 0; j < 15; j++)
		{
			mazeLayout[i][j] = tempMaze[i][j];

			if(mazeLayout[i][j] == 1)
			{
				MyImage* wall = new MyImage(40 * j, 40 * i, 1, pathPrefix + "assets/sprites/wall.png", "Wall");
			}

			else if(mazeLayout[i][j] == 2)
			{
				MyImage* key = new MyImage(40 * j, 40 * i, 2, pathPrefix + "assets/sprites/key.png", "Key");
			}

			else if(mazeLayout[i][j] == 3)
			{
				MyImage* door = new MyImage(40 * j, 40 * i, 2, pathPrefix + "assets/sprites/door.png", "Door");
			}
		}
	}

	start.x = 1;
	start.y = 13;

	end.x = 13;
	end.y = 13;

	doorPos.x = 8;
	doorPos.y = 6;

	currentPos = start;

	autoSolver = _autoSolver;

	if(autoSolver)
	{
		// Show players starting point with red rect.
		MyImage* red = new MyImage(40 * start.x, 40 * start.y, 2, pathPrefix + "assets/sprites/red.png", "Visited");
		solverVisual.Push(red);

		attemptedMoves = new MyText(220, 620, 4, "Attempted moves: 0", 15, "Attempted Moves");
		totalMoves = new MyText(220, 635, 4, "Total moves: 0", 15, "Total Moves");

		nAttemptedMoves = 0;
	}

	else
	{
		Player* player = new Player(start, 4, 100, 100, "Player");
	}

	startText = new MyText(40 * start.x + 3, 40 * start.y - 3, 3, "S", 40, "Start Icon");
	endText = new MyText(40 * end.x + 3, 40 * end.y - 3, 3, "E", 40, "End Icon");

	MyImage* infoBox = new MyImage(200, 600, 4, pathPrefix + "assets/sprites/infobox.png", "Info Box");
	MyImage* inventoryBox = new MyImage(0, 600, 4, pathPrefix + "assets/sprites/inventorybox.png", "Inventory Box");

	Button* returnButton = new Button(460, 685, 4, "Return", 20, "Return Button", []() { SceneManager::ChangeScene(SceneManager::MENU); } );

}

void Maze::Update()
{
	if(autoSolver)
	{
		AutoSolverStep();
	}

	return;
}

void Maze::Destroy()
{
	for(int i = 0; i < 127; i++)
	{
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Wall"));
	}

	for(int i = 0; i < 50; i++)
	{
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Visited"));
	}

	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Info Box"));
	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Inventory Box"));
	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Start Icon"));
	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("End Icon"));
	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Return Button"));
	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key"));
	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Door"));
	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Attempted Moves"));
	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Total Moves"));
	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Player"));
	GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key Collected"));


	return;
}

Drawable* Maze::GetDrawable()
{
	return nullptr;
}

void Maze::AutoSolverStep()
{
	// First, try to move in any direction, not obstructed by a wall,
	// and not previously visited.
	if(mazeLayout[currentPos.y - 1][currentPos.x] % 2 == 0
		&& solverVisited[currentPos.y - 1][currentPos.x] == false)
	{
		// Move up
		solverMovement.Push('u');
		solverVisited[currentPos.y - 1][currentPos.x] = true;

		MyImage* red = new MyImage(40 * currentPos.x, 40 * --currentPos.y, 2, pathPrefix + "assets/sprites/red.png", "Visited");
		solverVisual.Push(red);

		attemptedMoves->UpdateText("Attempted moves: " + std::to_string(++nAttemptedMoves), 15);
	}

	else if(mazeLayout[currentPos.y][currentPos.x + 1] % 2 == 0
			&& solverVisited[currentPos.y][currentPos.x + 1] == false)
	{
		// Move right
		solverMovement.Push('r');
		solverVisited[currentPos.y][currentPos.x + 1] = true;

		MyImage* red = new MyImage(40 * ++currentPos.x, 40 * currentPos.y, 2, pathPrefix + "assets/sprites/red.png", "Visited");
		solverVisual.Push(red);

		attemptedMoves->UpdateText("Attempted moves: " + std::to_string(++nAttemptedMoves), 15);
	}

	else if(mazeLayout[currentPos.y][currentPos.x - 1] % 2 == 0
			&& solverVisited[currentPos.y][currentPos.x - 1] == false)
	{
		// Move left
		solverMovement.Push('l');
		solverVisited[currentPos.y][currentPos.x - 1] = true;

		MyImage* red = new MyImage(40 * --currentPos.x, 40 * currentPos.y, 2, pathPrefix + "assets/sprites/red.png", "Visited");
		solverVisual.Push(red);

		attemptedMoves->UpdateText("Attempted moves: " + std::to_string(++nAttemptedMoves), 15);
	}

	else if(mazeLayout[currentPos.y + 1][currentPos.x] % 2 == 0
			&& solverVisited[currentPos.y + 1][currentPos.x] == false)
	{
		// Move down
		solverMovement.Push('d');
		solverVisited[currentPos.y + 1][currentPos.x] = true;

		MyImage* red = new MyImage(40 * currentPos.x, 40 * ++currentPos.y, 2, pathPrefix + "assets/sprites/red.png", "Visited");
		solverVisual.Push(red);

		attemptedMoves->UpdateText("Attempted moves: " + std::to_string(++nAttemptedMoves), 15);
	}

	else
	{
		// Backtrack
		char lastMove = solverMovement.Pop();

		if(lastMove == 'u')
		{
			currentPos.y++;
			GameObject::objects->Delete(GameObject::objects->GetLink(solverVisual.Pop()));
		}

		else if(lastMove == 'r')
		{
			currentPos.x--;
			GameObject::objects->Delete(GameObject::objects->GetLink(solverVisual.Pop()));
		}

		else if(lastMove == 'l')
		{
			currentPos.x++;
			GameObject::objects->Delete(GameObject::objects->GetLink(solverVisual.Pop()));
		}

		else if(lastMove == 'd')
		{
			currentPos.y--;
			GameObject::objects->Delete(GameObject::objects->GetLink(solverVisual.Pop()));
		}
	}

	if(mazeLayout[currentPos.y][currentPos.x] == 2)
	{
		mazeLayout[doorPos.y][doorPos.x] = 0;
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key"));

		MyImage* keyCollected = new MyImage(20, 620, 2, pathPrefix + "assets/sprites/key.png", 3.5f, "Key Collected");
	}

	if(currentPos == doorPos)
	{
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Door"));
		GameObject::objects->Delete(GameObject::objects->GetLinkWithLabel("Key Collected"));
	}

	if(currentPos == end)
	{
		autoSolver = false;
	}

	totalMoves->UpdateText("Total moves: " + std::to_string(solverMovement.top), 15);

	// Pause program for visual effect while using autosolver
	sleep(milliseconds(1000/20));
}
