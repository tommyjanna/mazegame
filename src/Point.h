// Point.h
// Class name: 			 Point
// Description of class: Point data structure containing integers x and y.
// Date Created:		 June 1, 2019
// Created by:			 Tommy Janna

#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point();
	Point(int _x, int _y);
	int x;
	int y;
	
	// Overload (==) to check if two points are equal.
	bool operator ==(const Point& p)
	{
		if(x == p.x && y == p.y)
			return true;
		
		else
			return false;
	}
};

#endif
