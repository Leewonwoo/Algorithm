#pragma once
#ifndef _LINKEDLIST12_H
#define _LINKEDLIST12_H

#include "List.h"

#include <iostream>

template <class T>
class LinkedList
{
private:

	int _size;
	List<T>* Head;
	List<T>* Tail;

public:

	LinkedList();
	~LinkedList();
	void push(T e);
	T pop();
	void delete_elem(T e);
	void search_elem(T e);

	int size();

	T operator[](int i);

};

template<class T>
LinkedList<T>::LinkedList()
{
	_size = 0;
	Head = NULL;
	Tail = NULL;
}

template<class T>
void LinkedList<T>::push(T _elem)
{

	List<T>* newElem = new List<T>();
	newElem->setNext(NULL);
	newElem->setData(_elem);

	if (Head == NULL)
	{
		Head = newElem;
	}
	else
	{
		Tail->setNext(newElem);
	}

	Tail = newElem;

	_size++;

}

template<class T>
T LinkedList<T>::pop()
{

	List<T>* Cur = Head;

	while (Cur->getNext() != Tail)
	{
		Cur = Cur->getNext();
	}

	List<T>* Del = Tail;

	T temp = Tail->getData();

	Tail = Cur;

	delete[]Del;

	_size--;

	return temp;

}

template<class T>
void LinkedList<T>::delete_elem(T _elem)
{

	_size--;

	List<T>* Cur = Head;
	List<T>* Prev = NULL;
	while (Cur->getData() != _elem)
	{
		Prev = Cur;
		Cur = Cur->getNext();
	}

	if (Cur == NULL)
	{
		cout << "찾는 데이터가 없습니다." << endl;
		return;
	}
	else if (Cur == Head)
	{
		Head = Head->getNext();
	}
	else if (Cur->getNext() == NULL)
	{
		pop();
		return;
	}
	else
	{
		Prev->setNext(Cur->getNext());
	}

	List<T>* Del = Cur;

	delete[]Del;



}

template<class T>
void LinkedList<T>::search_elem(T _elem)
{

	List<T>* Cur = Head;
	while (Cur->getData() != _elem)
	{
		Cur = Cur->getNext();
	}
	if (Cur != NULL)
	{
		cout << "Find Data" << endl;
	}
}

template<class T>
T LinkedList<T>::operator[](int i)
{
	int _i = 0;
	List<T>* Cur = Head;
	while (_i < i)
	{

		Cur = Cur->getNext();
		_i++;

	}

	return Cur->getData();

}

template<class T>
int LinkedList<T>::size()
{
	return _size;
}

template<class T>
LinkedList<T>::~LinkedList()
{

}
#endif // !_LINKEDLIST12_H
