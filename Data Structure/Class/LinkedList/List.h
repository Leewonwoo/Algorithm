#pragma once
#ifndef _LIST12_H_
#define _LIST12_H_

#include <iostream>

template<class T>
class List
{
private:
	T data;
	List* Next;
public:
	List()
	{
		Next = NULL;
	}

	void setNext(List* _elem)
	{
		Next = _elem;
	}

	void setData(T data)
	{
		this->data = data;
	}

	List* getNext()
	{
		return Next;
	}

	T getData()
	{
		return this->data;
	}
};

#endif // !_LIST12_H_