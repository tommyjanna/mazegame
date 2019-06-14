// Stack.h
// Class name: 			 Stack
// Description of class: Stack data structure.
// Date Created:		 June 1, 2019
// Last Modified:		 June 1, 2019
// Created by:			 Tommy Janna

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
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
public:
	Stack();
	
	T Pop();
	T Peek();
	void Push(T _value);
	
	int GetSize();
};

#include "Stack.tpp"

#endif
