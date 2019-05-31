// LinkedList.h
// Class Name:		  LinkedList
// Class Description: It's a linked list. What else do you want...
// Date Created:	  April 2, 2019
// Last Modified:	  May 23, 2019
// Created by:		  Tommy Janna

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "GameObject.h"

using namespace std;

class GameObject;

class LinkedList
{
private:
	// Nested class Link representing each item in the list.
	class Link
	{
	public:
		Link* GetNext();
		void SetNext(Link*);

		Link* GetPrev();
		void SetPrev(Link*);

		GameObject* GetContent();
		void SetContent(GameObject*);

	private:
		Link* next; // Next link in list
		Link* prev; // Previous link in list
		GameObject* content;
	};

	Link* first;
	Link* last;
	int size;

public:
	LinkedList(); // Initialize empty list

	void Add(Link*, Link*); // Add given link and destination
	void Add(GameObject*, Link*); // Add given content and destination
	void Delete(Link*); // Deletes item in list
	Link* Remove(Link*); // Removes item in list and returns it to be transferred
	Link* GetLink(GameObject*); // Finds link with content
	Link* GetLinkAt(int); // Finds link at location
	Link* GetLinkWithLabel(string); // Finds link with given label
	Link* GetFirst();
	Link* GetLast();
	int GetSize();

};

#endif
