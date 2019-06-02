// Stack.h
// Class name: 			 Stack
// Description of class: Stack data structure.
// Date Created:		 June 1, 2019
// Last Modified:		 June 1, 2019
// Created by:			 Tommy Janna

#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 100

template <class T>
class Stack
{
public:
	Stack();
	
	T Pop();
	void Push(T _value);

	int top;

private:
	// Limit of 100 items.
	T content[MAX_STACK_SIZE];
};

#include "Stack.tpp"

#endif
