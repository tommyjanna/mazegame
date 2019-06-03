// Maze.h
// Class name: 			 Maze
// Description of class: Maze that contains all corresponding gameobjects,
//						 and functionality for the auto-solver.
// Date Created:		 May 27, 2019
// Last Modified:		 May 27, 2019
// Created by:			 Tommy Janna

#ifndef MAZE_H
#define MAZE_H

#include "GameObject.h"
#include "Game.h"
#include "GameObjects/Image.h"
#include "GameObjects/Text.h"
#include "Stack.h"
#include "Point.h"

class Maze : public GameObject
{
public:
    Maze(bool _autoSolver);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;

private:
	Uint8 mazeLayout[15][15];

	Point start;
	Point end;
	Point currentPos;

	string pathPrefix;

	MyText* startText;
	MyText* endText;

	// Data pertaining to the autosolver
	bool autoSolver;
	void AutoSolverStep();
	Stack<char> solverMovement;
	Stack<MyImage*> solverVisual;
	bool solverVisited[15][15];
	MyText* attemptedMoves;
	MyText* totalMoves;
	int nAttemptedMoves;
};

#endif
