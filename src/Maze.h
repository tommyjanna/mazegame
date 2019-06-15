// Maze.h
// Class name: 			 Maze
// Description of class: Maze that contains all corresponding gameobjects,
//						 and functionality for the auto-solver.
// Date Created:		 May 27, 2019
// Created by:			 Tommy Janna

#ifndef MAZE_H
#define MAZE_H

#include "GameObject.h"
#include "Game.h"
#include "GameObjects/Image.h"
#include "GameObjects/Text.h"
#include "GameObjects/Player.h"
#include "GameObjects/Riddler.h"
#include "GameObjects/Turret.h"
#include "GameObjects/Button.h"
#include "Stack.h"
#include "Point.h"

#ifndef _WIN32
#define PATH_PREFIX "../"
#else
#define PATH_PREFIX ""
#endif

class Riddler;

class Maze : public GameObject
{
public:
    Maze(bool _autoSolver);

    void Update() override;
    void Destroy() override;
    Drawable* GetDrawable() override;

    static Uint8 GetCell(Uint8 _x, Uint8 _y);
    static void SetCell(Uint8 _x, Uint8 _y, Uint8 _type);
    static Riddler* GetRiddler();

private:
	static Uint8 mazeLayout[15][15];
	static Riddler* riddler;

	Point start;
	Point end;
	Point currentPos;
	Point doorPos;
	Point riddlerPos;
	Point turretPos1;
	Point turretPos2;
	
	MyText* startText;
	MyText* endText;

	// Data pertaining to the autosolver
	bool autoSolver;
	void AutoSolverStep();
	Stack<char> solverMovement; // Stack containing all previous movements.
	Stack<MyImage*> solverVisual; // Visual representation of solver movements.
	bool solverVisited[15][15]; // Memorize locations solver has visited to avoid loops.
	MyText* attemptedMoves;
	MyText* totalMoves;
	int nAttemptedMoves;
};

#endif
