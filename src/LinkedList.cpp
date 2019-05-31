// LinkedList.cpp
// Implementation of the LinkedList class
// Date Created:	April 2, 2019
// Last Modified:	May 23, 2019
// Created by:		Tommy Janna

#include "LinkedList.h"

LinkedList::LinkedList()
{
	size = 0;
	first = nullptr;
	last = nullptr;
}

LinkedList::Link* LinkedList::Link::GetNext()
{
	return next;
}

void LinkedList::Link::SetNext(Link* _link)
{
	next = _link;
	return;
}

LinkedList::Link* LinkedList::Link::GetPrev()
{
	return prev;
}

void LinkedList::Link::SetPrev(Link* _link)
{
	prev = _link;
	return;
}

GameObject* LinkedList::Link::GetContent()
{
	return content;
}

void LinkedList::Link::SetContent(GameObject* _content)
{
	content = _content;
	return;
}

void LinkedList::Add(Link* _newLink, Link* _destination)
{
	size++;

	if(first == nullptr) // List is empty.
	{
		_newLink->SetNext(nullptr);
		_newLink->SetPrev(nullptr);

		first = _newLink;
		last = _newLink;
	}

	else if(last == _destination) // Adding new link to end of list.
	{
		_newLink->SetNext(nullptr);
		_newLink->SetPrev(_destination);

		_destination->SetNext(_newLink);

		last = _newLink;
	}

	else
	{
		_newLink->SetNext(_destination->GetNext());
		_newLink->SetPrev(_destination);
		_destination->GetNext()->SetPrev(_newLink);
		_destination->SetNext(_newLink);
	}

	return;
}

void LinkedList::Add(GameObject* _content, Link* _destination)
{
	Link* newLink = new Link; // Creates new link with content information to be added to list.
	newLink->SetContent(_content);
	Add(newLink, _destination);
	return;
}

void LinkedList::Delete(Link* _link)
{
	if (first != nullptr && _link != nullptr) // List cannot be empty and link to delete cannot be empty
	{
		size--;

		if (first == _link && last == _link) // Deleting single and only link in list
		{
			first = nullptr;
			last = nullptr;
		}

		else if (first == _link) // Deleting first link in list
		{
			_link->GetNext()->SetPrev(nullptr);
			first = _link->GetNext();
		}

		else if (last == _link) // Deleting last link in list
		{
			_link->GetPrev()->SetNext(nullptr);
			last = _link->GetPrev();
		}

		else
		{
			_link->GetPrev()->SetNext(_link->GetNext());
			_link->GetNext()->SetPrev(_link->GetPrev());
		}

		delete(_link);
	}

	return;
}

LinkedList::Link* LinkedList::Remove(Link* _link)
{
	if (first != nullptr && _link != nullptr) // List cannot be empty and link to remove cannot be empty
	{
		size--;

		if (first == _link && last == _link) // Removing single and only link in list
		{
			first = nullptr;
			last = nullptr;
		}

		else if (first == _link) // Removing first link in list
		{
			_link->GetNext()->SetPrev(nullptr);
			first = _link->GetNext();
		}

		else if (last == _link) // Removing last link in list
		{
			_link->GetPrev()->SetNext(nullptr);
			last = _link->GetPrev();
		}

		else
		{
			_link->GetPrev()->SetNext(_link->GetNext());
			_link->GetNext()->SetPrev(_link->GetPrev());
		}

		return _link;
	}

	return nullptr; // Link does not exist.
}

LinkedList::Link* LinkedList::GetLink(GameObject* _content)
{
	Link* temp = first;

	if (temp == nullptr) // Empty list
		return nullptr;

	// Content numbers are NOT always sequential, so can't assume must be less than size.
	while (temp->GetContent() != _content)
	{
		if (temp == last) // Reached end of list.
			return nullptr;

		temp = temp->GetNext();
	}

	return temp; // Found link
}

LinkedList::Link* LinkedList::GetLinkAt(int _location)
{
	Link* temp = first;

	if (temp == nullptr) // Empty list
		return nullptr;

	for(int i = 0; i < _location; i++)
	{
		if(temp == last) // Reached end of list.
			return nullptr;

		temp = temp->GetNext();
	}

	return temp; // Found link
}

LinkedList::Link* LinkedList::GetLinkWithLabel(string _label)
{
	Link* temp = first;

	if (temp == nullptr) // Empty list
		return nullptr;

	while (temp->GetContent()->GetLabel() != _label)
	{
		if (temp == last) // Reached end of list.
			return nullptr;

		temp = temp->GetNext();
	}

	return temp; // Found link
}

LinkedList::Link* LinkedList::GetFirst()
{
	return first;
}

LinkedList::Link* LinkedList::GetLast()
{
	return last;
}

int LinkedList::GetSize()
{
	return size;
}

