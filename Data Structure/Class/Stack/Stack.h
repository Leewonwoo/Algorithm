#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#include "List.h"
#include "ArrayList.h"

template <class T>
class Stack : public ArrayList
{

private:
	List<T>* Head;
	List<T>* Tail;

	int _size;

public:
	Stack()
	{
		_size = 0;
		Head = NULL;
		Tail = NULL;
	}

	~Stack()
	{

	}

	void push_back(T data)
	{

		List<T>* newNode = new List<T>();
		newNode->setData(data);
		newNode->setNext(NULL);

		if (Head == NULL)
		{
			Head = newNode;
		}
		else
		{
			newNode->setNext(Tail);
		}

		Tail = newNode;
		
		_size++;

	}

	void pop()
	{

		if (isEmpty()) { return; }

		List<T>* Del = Tail;

		if (Tail == Head) { Head = NULL; }

		Tail = Tail->getNext();

		_size--;

		delete[]Del;

	}

	template <class T>
	T pop()
	{

		if (isEmpty()) { return -1; }

		List<T>* Del = Tail;

		if (Tail == Head) { Head = NULL; }

		Tail = Tail->getNext();

		T data = Del->getData();

		delete[]Del;

		_size--;

		return data;

	}

	int size()
	{
		return _size;
	}

	bool isEmpty()
	{
		return Head == NULL ? true : false;
	}

};

#endif // !_STACK_H_
