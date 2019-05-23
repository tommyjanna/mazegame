// List.h
// Class Name:		  List
// Class Description: Stores a list of unique numbers in an array
//					  and the graphical data for each node.
// Date Created:	  May 8, 2019
// Last Modified:	  May 11, 2019
// Created by:		  Tommy Janna

#ifndef LIST_H
#define LIST_H

#define SIZE 20
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <SFML/Graphics.hpp>

using namespace sf;

class List
{
private:
	// Nested class Node representing each item in the list.
	class Node
	{
	public:
		Node(int); // Creates node given content.
		int GetContent();
		void SetContent(int);
		int GetHeight();
		void SetColour(Color);
		
		void Draw(int, int); // Updates rect position given (x, y).
		
		RectangleShape rectangle;
	private:
		int content;
		int height, width;
	};

	int size;
	Node* nodes[SIZE];
	
	// Keeps track of position in the sort process.
	int currentSortIndex;
	int currentIndex;
	
	// Is list still being sorted?
	bool sorting;
		
public:
	List(int); // Creates list given size.
	
	void BubbleSortStep(); // Preforms one step of the bubble sort algorithm.
	void Shuffle(); // Swap each item a new random location in the array.
	Node* GetNodeAt(int); // Return node at given position in array.
	bool IsSorting(); // Returns if list is still being sorted.
	void Sort(); // Set sort flag to true.
	void Draw(); // Decides how to arrange Nodes the calls each Draw().
};

#endif
