// Stack.tpp
// Template implementation of the Stack class
// Date Created:	June 1, 2019
// Last Modified:	June 1, 2019
// Created by:		Tommy Janna

template <class T>
Stack<T>::Node::Node(T _content, Node* _last)
{
	content = _content;
	last = _last;
}

template <class T>
T Stack<T>::Node::GetContent()
{
	return content;
}

template <class T>
Stack<T>::Stack()
{
	top = nullptr;
	size = 0;
}

template <class T>
void Stack<T>::Push(T _value)
{
	Node* node = new Node(_value, top);
	top = node;
	size++;

	return;
}

template <>
inline char Stack<char>::Pop()
{
	if(top != nullptr)
	{
		char content = top->GetContent();
		top = top->last;
		size--;
		return content;
	}

	return '\0';
}

template<>
inline MyImage* Stack<MyImage*>::Pop()
{
	if(top != nullptr)
	{
		MyImage* content = top->GetContent();
		top = top->last;
		size--;
		return content;
	}

	return nullptr;
}

template <>
inline char Stack<char>::Peek()
{
	if(top != nullptr)
	{
		return top->GetContent();
	}

	return '\0';
}

template<>
inline MyImage* Stack<MyImage*>::Peek()
{
	if(top != nullptr)
	{
		return top->GetContent();
	}

	return nullptr;
}

template <class T>
int Stack<T>::GetSize()
{
	return size;
}
