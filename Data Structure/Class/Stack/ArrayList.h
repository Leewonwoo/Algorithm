#pragma once
#ifndef _ARRAY_H_
#define _ARRAY_H_

class ArrayList
{

private:



public:
	ArrayList();
	~ArrayList();
	virtual void pop() = 0;
	virtual bool isEmpty() = 0;
	virtual int size() = 0;
};

ArrayList::ArrayList()
{
}

ArrayList::~ArrayList()
{
}


#endif // !_ARRAY_H_
