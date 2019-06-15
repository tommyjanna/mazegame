// Stack.h
// Class name: 			 Stack
// Description of class: Stack data structure.
// Date Created:		 June 1, 2019
// Created by:			 Tommy Janna

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
public:
	Stack();
	
	T Pop(); // Return top while deleting it.
	T Peek(); // Return top without deleting.
	void Push(T _value); // Add new item.
	
	int GetSize();
private:
	class Node
	{
	public:
		Node(T _content, Node* _last);
		Node* last;
		
		T GetContent();
	private:
		T content;
	};

	Node* top;
	int size;
};

// The internet told me to put it here.
#include "Stack.tpp"

#endif
