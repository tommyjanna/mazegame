// Stack.tpp
// Template implementation of the Stack class
// Date Created:	June 1, 2019
// Last Modified:	June 1, 2019
// Created by:		Tommy Janna

template <class T>
Stack<T>::Stack()
{
	top = 0;
}

template <class T>
void Stack<T>::Push(T _value)
{
	if(top < MAX_STACK_SIZE - 1)
	{
		content[++top] = _value;
	}

	return;
}

template <>
inline char Stack<char>::Pop()
{
	if(top > 0)
	{
		return content[top--];
	}
	
	return '\0';
}

template<>
inline MyImage* Stack<MyImage*>::Pop()
{
	if(top > 0)
	{
		return content[top--];
	}
	
	return nullptr;
}
