// List.cpp
// Implementation of the List class
// Date Created:	May 8, 2019
// Last Modified:	May 11, 2019
// Created by:		Tommy Janna

#include "List.h"


using namespace sf;
using namespace std;

List::List(int _size)
{
	Node* newNode;
	currentSortIndex = 0;
	currentIndex = 0;
	
	size = _size;

	// Generates list from 1 - size.
	for(int i = 0; i < size; i++)
	{
	    newNode = new Node(i + 1);
		nodes[i] = newNode;
	}
}

void List::Shuffle()
{
	int nodeToSwap;
	Node* tempNode;
	
	for(int i = 0; i < size; i++)
	{
		// Pick random position in array to swap each Node with.
		nodeToSwap = rand() % size;
		tempNode = nodes[nodeToSwap];
		nodes[nodeToSwap] = nodes[i];
		nodes[i] = tempNode;
	}
	
	return;
}

void List::BubbleSortStep()
{
	Node* tempNode;
	
	if(currentSortIndex != 0) // If isn't first comparison, reset colours to white.
	{
		nodes[currentSortIndex - 1]->SetColour(Color::White);
		nodes[currentSortIndex]->SetColour(Color::White);
	}
	
	if(currentSortIndex < size - currentIndex - 1) // Haven't compared with all items.
	{
		// Set comparing nodes to red.
		nodes[currentSortIndex]->SetColour(Color::Red);
		nodes[currentSortIndex + 1]->SetColour(Color::Red);
	
		if(nodes[currentSortIndex]->GetContent() > nodes[currentSortIndex + 1]->GetContent()) // Comparison
		{
			// Swap nodes.
			tempNode = nodes[currentSortIndex+ 1];
			nodes[currentSortIndex + 1] = nodes[currentSortIndex];
			nodes[currentSortIndex] = tempNode;
		}
		
		currentSortIndex++;
		
		// Halt the program for 0.1 s for visual effect.
		sleep(milliseconds(100));
	}
	
	else // Reached end of list, restart with higher (lower) finish index.
	{
		currentSortIndex = 0;
		currentIndex++;
	}
	
	if(currentIndex >= size - 1) // Sort complete.
	{
		sorting = false;
	}
	
	return;
}

List::Node* List::GetNodeAt(int _location)
{
	return nodes[_location];
}

bool List::IsSorting()
{
	return sorting;
}

void List::Sort()
{
	sorting = true;
	return;
}
void List::Draw()
{	
	for(int i = 0; i < size; i++) // For each node in list.
	{
		// Draw such that,
		//					There is a 10 px margin from the bottom, left and top.
		//					Each bar has 5 px between it and another bar.
		//					NOTE: SFML counts from the top left as the origin.
		nodes[i]->Draw(10 + ((SCREEN_WIDTH - 20) / SIZE) * i,
						SCREEN_HEIGHT - 10 - nodes[i]->GetHeight());
	}
		
	return;
}

List::Node::Node(int _content)
{
	content = _content;
	
	// Screen height subtract 20 for 10 px margin on both sides.
	// Devided by size (max value) then multiply by content for ratio.
	height = (SCREEN_HEIGHT - 20) / SIZE * content;

	// Constant width across all bars.
	width = (SCREEN_WIDTH - 20) / SIZE - 5;

    rectangle.setSize(Vector2f(width, height));
}


int List::Node::GetContent()
{
	return content;
}

void List::Node::SetContent(int _content)
{
	content = _content;
	return;
}

int List::Node::GetHeight()
{
	return height;
}

void List::Node::SetColour(Color _colour)
{
	rectangle.setFillColor(_colour);
}

void List::Node::Draw(int _xPos, int _yPos)
{
	rectangle.setPosition(_xPos, _yPos);	
}
